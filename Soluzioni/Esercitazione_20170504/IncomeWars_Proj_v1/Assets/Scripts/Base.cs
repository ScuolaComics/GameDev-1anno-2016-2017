using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class Base : Target
{
	public Player editorOwner;

	public Text hpText;

	// Use this for initialization
	void Start () 
	{ 
		owner = editorOwner;
		UpdateHUD();
	}

	void UpdateHUD()
	{
		hpText.text = currentHP.ToString();
	}

	protected override void Loss(int loss)
	{
		base.Loss(loss);
		UpdateHUD();
	}

	void OnDestroy()
	{
		gameController.GameOver(owner);
	}
}
