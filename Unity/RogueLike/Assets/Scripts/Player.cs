using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Player : MovingObject
{
	public int wallDamage = 1;
	public int pointsPerFood = 10;
	public int pointsPerSoda = 20;
	public float restartLevelDelay = 1f;

	private Animator _animator;
	private int _food;

	// Use this for initialization
	protected override void Start () 
	{
		_animator = GetComponent<Animator> ();
		_food = GameManager.instance.playerFoodPoints;

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
			GameManager.instance.GameOver ();
		}
	}

	protected override void AttemptMove<T> (int xDir, int yDir)
	{
		base.AttemptMove <T> (xDir, yDir);

		_food--;

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
		}
	}

	protected override void OnMove ()
	{
		// TODO Add Audio Effect
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
			other.gameObject.SetActive (false);
		}
		else if (other.CompareTag ("Soda")) 
		{
			_food += this.pointsPerSoda;
			other.gameObject.SetActive (false);
		}
	}

	public void LoseFood (int loss)
	{
		_animator.SetTrigger ("PlayerHit");
		_food -= loss;
		CheckIfGameOver ();
	}
}
