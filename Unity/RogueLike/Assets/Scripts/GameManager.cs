using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
	public static GameManager instance = null;

	public int playerFoodPoints = 100;
	[HideInInspector] public bool playerTurn = true;

	private BoardManager _boardManager;
	private int _level = 3;

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
	}

	// Use this for initialization
	void Start ()
	{
		this.InitGame ();
	}

	private void InitGame ()
	{
		_boardManager.SetupScene (_level);
	}

	public void GameOver ()
	{
		this.enabled = true;
	}
	
	// Update is called once per frame
	void Update () 
	{
		
	}
}
