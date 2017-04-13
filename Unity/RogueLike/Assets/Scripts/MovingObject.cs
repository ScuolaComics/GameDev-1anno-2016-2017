using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class MovingObject : MonoBehaviour 
{
	public float moveTime = .1f;
	public LayerMask _blockingLayer;

	private BoxCollider2D _boxCollider;
	private Rigidbody2D _rigidBody;
	private float _inverseMoveTime;



	// Use this for initialization
	protected virtual void Start () 
	{
		_boxCollider = GetComponent<BoxCollider2D> ();
		_rigidBody = GetComponent<Rigidbody2D> ();
		_inverseMoveTime = 1f / this.moveTime;
	}

	protected IEnumerator SmoothMovement (Vector3 end)
	{
		float sqrRemainingDistance = (transform.position - end).sqrMagnitude;

		while (sqrRemainingDistance > float.Epsilon) 
		{
			Vector3 newPosition = Vector3.MoveTowards (_rigidBody.position, end, _inverseMoveTime * Time.deltaTime);
			_rigidBody.MovePosition (newPosition);
			sqrRemainingDistance = (transform.position - end).sqrMagnitude;
			yield return null;
		}
	}

	protected abstract void OnCantMove<T> (T component) where T : Component;

	protected abstract void OnMove ();

	protected bool Move (int xDir, int yDir, out RaycastHit2D hit)
	{
		Vector2 start = transform.position;
		Vector2 end = start + new Vector2 (xDir, yDir);

		_boxCollider.enabled = false;
		hit = Physics2D.Linecast (start, end, _blockingLayer);
		_boxCollider.enabled = true;

		if (hit.transform == null) 
		{
			StartCoroutine (SmoothMovement (end));
			return true;
		}
		return false;
	}

	protected virtual void AttemptMove <T> (int xDir, int yDir) where T : Component
	{
		RaycastHit2D hit;
		bool canMove = Move (xDir, yDir, out hit);

		if (canMove) 
		{
			OnMove ();
		}
		else 
		{
			T hitComponent = hit.transform.GetComponent<T> ();

			if (hitComponent != null) 
			{
				OnCantMove (hitComponent);
			}
		}
	}
}
