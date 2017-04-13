using System.Collections;
using System.Collections.Generic;
using UnityEngine;

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
	
	// Update is called once per frame
	void Update () {
		
	}
}
