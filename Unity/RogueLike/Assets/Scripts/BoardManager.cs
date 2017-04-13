using System.Collections;
using UnityEngine;
using System;
using Random = UnityEngine.Random;
using System.Collections.Generic;

public class BoardManager : MonoBehaviour
{
	[Serializable]
	public class Count
	{
		public int minimum;
		public int maximum;

		public Count (int minimum, int maximum)
		{
			this.minimum = minimum;
			this.maximum = maximum;
		}
	}

	public int columns = 8;
	public int rows = 8;

	public Count wallCount = new Count (5, 9);
	public Count foodCount = new Count (1, 5);

	public GameObject exit;

	public GameObject[] floorTiles;
	public GameObject[] wallTiles;
	public GameObject[] foodTiles;
	public GameObject[] enemyTiles;
	public GameObject[] outerWallTiles;

	private Transform _boardHolder;

	private List<Vector3> _gridPositions = new List<Vector3> ();

	private void InitializeGridPosition()
	{
		_gridPositions.Clear ();

		for (int x = 1; x < this.columns - 1; x++) 
		{
			for (int y = 1; y < this.rows - 1; y++) 
			{
				_gridPositions.Add (new Vector3(x, y, 0f));
			}
		}
	}

	private void BoardSetup()
	{
		_boardHolder = new GameObject ("Board").transform;

		for (int x = -1; x < this.columns + 1; x++) 
		{
			for (int y = -1; y < this.rows + 1; y++) 
			{
				GameObject toInstantiate = this.floorTiles[Random.Range(0, this.floorTiles.Length)];

				if ( x == -1 || x == this.columns || y == -1 || y == this.rows ) 
				{
					toInstantiate = this.outerWallTiles[Random.Range(0, this.outerWallTiles.Length)];
				}

				Instantiate (toInstantiate, new Vector3 (x, y, 0f), Quaternion.identity, _boardHolder);
			}
		}
	}

	private Vector3 RandomPosition()
	{
		int randomIndex = Random.Range (0, _gridPositions.Count);
		Vector3 randomPosition = _gridPositions [randomIndex];
		_gridPositions.RemoveAt (randomIndex);
		return randomPosition;
	}

	private void LayoutObjectAtRandom (GameObject[] tileArray, int minimum, int maximum)
	{
		int objectCount = Random.Range (minimum, maximum + 1);

		for (int i = 0; i < objectCount; i++) 
		{
			Vector3 randomPosition = this.RandomPosition ();
			GameObject tileChoice = tileArray [Random.Range (0, tileArray.Length)];
			Instantiate (tileChoice, randomPosition, Quaternion.identity);
		}
	}

	public void SetupScene(int level)
	{
		this.BoardSetup ();
		this.InitializeGridPosition ();
		this.LayoutObjectAtRandom (this.wallTiles, this.wallCount.minimum, this.wallCount.maximum);
		this.LayoutObjectAtRandom (this.foodTiles, this.foodCount.minimum, this.foodCount.maximum);
		int enemyCount = (int)Mathf.Log (level, 2f);
		this.LayoutObjectAtRandom (this.enemyTiles, enemyCount, enemyCount);
		Instantiate (this.exit, new Vector3(this.columns - 1, this.rows - 1), Quaternion.identity);
	}

	// Use this for initialization
	void Start () 
	{
		
	}
	
	// Update is called once per frame
	void Update () 
	{
		
	}
}
