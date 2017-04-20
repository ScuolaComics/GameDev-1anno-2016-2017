using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
	public static GameManager instance = null;

	public int playerFoodPoints = 100;
	[HideInInspector] public bool playerTurn = true;

	public float turnDelay = .1f;
	public float levelStartDelay = 2f;

	private BoardManager _boardManager;
	private int _level = 1;

	private List<Enemy> _enemies;
	private bool _enemiesMoving;

	private Text _levelText;
	private GameObject _levelImage;
	private bool _doingSetup;

	private bool _firstRun = true;

	void Awake ()
	{
		// Singleton Pattern - Start
		if (instance == null) 
		{
			instance = this;
		}
		else if (instance != this) 
		{
			Destroy (gameObject);
		}
		DontDestroyOnLoad (gameObject);
		// Singleton Pattern - End

		_boardManager = GetComponent<BoardManager> ();
		_enemies = new List<Enemy> ();
	}

	// Use this for initialization
	void Start ()
	{
		this.InitGame ();
	}

	private void InitGame ()
	{
		_doingSetup = true;

		_levelImage = GameObject.Find ("LevelImage");
		_levelText = GameObject.Find ("LevelText").GetComponent<Text> ();
		_levelText.text = "Day " + _level;
		_levelImage.SetActive (true);

		Invoke ("HideLevelImage", this.levelStartDelay);

		_enemies.Clear ();
		_boardManager.SetupScene (_level);
	}

	private void HideLevelImage ()
	{
		_levelImage.SetActive (false);
		_doingSetup = false;
	}

	public void GameOver ()
	{
		_levelText.text = "After " + _level + " days, you starved!";
		_levelImage.SetActive (true);

		this.enabled = false;
	}
	
	// Update is called once per frame
	void Update () 
	{
		if (this.playerTurn || _enemiesMoving || _doingSetup) 
		{
			return;
		}

		StartCoroutine (MoveEnemies ());
	}

	IEnumerator MoveEnemies ()
	{
		_enemiesMoving = true;
		yield return new WaitForSeconds (this.turnDelay);
		if (_enemies.Count == 0) 
		{
			yield return new WaitForSeconds (this.turnDelay);
		}

		for (int i = 0; i < _enemies.Count; i++) 
		{
			_enemies [i].MoveEnemy ();
			yield return new WaitForSeconds (_enemies[i].moveTime);
		}

		_enemiesMoving = false;
		this.playerTurn = true;
	}

	public void AddEnemyToList (Enemy script)
	{
		_enemies.Add (script);
	}

	private void OnLevelFinishedLoading(Scene scene, LoadSceneMode mode)
	{
		if (_firstRun) 
		{
			_firstRun = false;
			return;
		}

		_level++;
		InitGame ();
	}

	void OnEnable ()
	{
		SceneManager.sceneLoaded += OnLevelFinishedLoading;
	}

	void OnDisable ()
	{
		SceneManager.sceneLoaded -= OnLevelFinishedLoading;
	}
}
