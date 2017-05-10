using UnityEngine;
using System;
using System.Collections;
using Random = UnityEngine.Random;

[Serializable]
public class Player
{
	public int index;
	public Color color;
	public string name;

	public Player(int index, Color color, string name)
	{
		this.index = index;
		this.color = color;
		this.name = name;
	}
}
