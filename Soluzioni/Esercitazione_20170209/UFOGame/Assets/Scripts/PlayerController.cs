using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerController : MonoBehaviour
{
	public float acceleration = 10.0f;
	public Text countText;
	public Text winText;

	private Rigidbody2D _rb2D;
	private int _count;

	// Use this for initialization
	void Start () 
	{
		_rb2D = this.gameObject.GetComponent<Rigidbody2D>();
		_count = 0;
		Debug.Assert(countText != null);
		countText.text = "Count: " + _count.ToString();
		Debug.Assert(winText != null);
		winText.gameObject.SetActive(false);
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	void FixedUpdate ()
	{
		float moveVertical = Input.GetAxis("Vertical");
		float moveHorizontal = Input.GetAxis("Horizontal");

		Vector2 force = new Vector2(moveHorizontal, moveVertical);
		force *= acceleration;
		_rb2D.AddForce(force);
	}

	void OnTriggerEnter2D(Collider2D other) 
	{
		if (other.CompareTag("PickUp"))
		{
			other.gameObject.SetActive(false);
			_count++;
			Debug.Assert(countText != null);
			countText.text = "Count: " + _count.ToString();

			if (_count >= 12)
			{
				Debug.Assert(winText != null);
				winText.gameObject.SetActive(true);
			}
		}
	}
}
