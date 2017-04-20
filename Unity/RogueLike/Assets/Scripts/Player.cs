using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class Player : MovingObject
{
	public int wallDamage = 1;
	public int pointsPerFood = 10;
	public int pointsPerSoda = 20;
	public float restartLevelDelay = 1f;

	public Text foodText;

	public AudioClip moveSound1;
	public AudioClip moveSound2;
	public AudioClip eatSound1;
	public AudioClip eatSound2;
	public AudioClip drinkSound1;
	public AudioClip drinkSound2;
	public AudioClip chopSound1;
	public AudioClip chopSound2;
	public AudioClip gameOverSound;

	private Animator _animator;
	private int _food;

	// Use this for initialization
	protected override void Start () 
	{
		_animator = GetComponent<Animator> ();
		_food = GameManager.instance.playerFoodPoints;
		this.foodText.text = "Food: " + _food;

		base.Start ();
	}

	private void OnDisable ()
	{
		GameManager.instance.playerFoodPoints = _food;
	}

	private void CheckIfGameOver ()
	{
		if (_food <= 0) 
		{
			SoundManager.instance.PlaySingle (this.gameOverSound);
			SoundManager.instance.musicSource.Stop ();
			GameManager.instance.GameOver ();
		}
	}

	protected override void AttemptMove<T> (int xDir, int yDir)
	{
		base.AttemptMove <T> (xDir, yDir);

		_food--;
		this.foodText.text = "Food: " + _food;

		CheckIfGameOver ();

		GameManager.instance.playerTurn = false;
	}
	
	// Update is called once per frame
	void Update () 
	{
		if (!GameManager.instance.playerTurn) {
			return;
		}
			
		int horizontal = 0;
		int vertical = 0;

		horizontal = (int)Input.GetAxisRaw ("Horizontal");
		vertical = (int)Input.GetAxisRaw ("Vertical");

		if (horizontal != 0) 
		{
			vertical = 0;
		}

		if (horizontal != 0 || vertical != 0) 
		{
			AttemptMove<Wall> (horizontal, vertical);
		}
	}

	protected override void OnCantMove <T> (T component)
	{
		Wall hitWall = component as Wall;
		if (hitWall != null) 
		{
			hitWall.DamageWall (this.wallDamage);
			_animator.SetTrigger ("PlayerChop");
			SoundManager.instance.RandomizeSfx (this.chopSound1, this.chopSound2);
		}
	}

	protected override void OnMove ()
	{
		SoundManager.instance.RandomizeSfx (this.moveSound1, this.moveSound2);
	}

	private void Restart ()
	{
		SceneManager.LoadScene (SceneManager.GetActiveScene ().name);
	}

	private void OnTriggerEnter2D (Collider2D other)
	{
		if (other.CompareTag ("Exit")) 
		{
			Invoke ("Restart", this.restartLevelDelay);
			this.enabled = false;
		}
		else if (other.CompareTag ("Food")) 
		{
			_food += this.pointsPerFood;
			this.foodText.text = "+" + this.pointsPerFood + " Food: " + _food;
			SoundManager.instance.RandomizeSfx (this.eatSound1, this.eatSound2);
			other.gameObject.SetActive (false);
		}
		else if (other.CompareTag ("Soda")) 
		{
			_food += this.pointsPerSoda;
			this.foodText.text = "+" + this.pointsPerSoda + " Food: " + _food;
			SoundManager.instance.RandomizeSfx (this.drinkSound1, this.drinkSound2);
			other.gameObject.SetActive (false);
		}
	}

	public void LoseFood (int loss)
	{
		_animator.SetTrigger ("PlayerHit");
		_food -= loss;
		this.foodText.text = "-" + loss + " Food: " + _food;
		CheckIfGameOver ();
	}
}
