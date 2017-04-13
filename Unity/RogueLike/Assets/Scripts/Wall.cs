using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Wall : MonoBehaviour
{
	public Sprite dmgSprite;
	public int hp = 4;

	private SpriteRenderer _spriteRenderer;

	void Awake ()
	{
		_spriteRenderer = GetComponent<SpriteRenderer> ();
	}

	public void DamageWall (int loss)
	{
		_spriteRenderer.sprite = this.dmgSprite;
		this.hp -= loss;

		if (this.hp <= 0) 
		{
			gameObject.SetActive (false);
		}
	}
}
