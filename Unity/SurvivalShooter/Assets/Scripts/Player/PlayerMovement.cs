using UnityEngine;

[RequireComponent (typeof(Animator))]
[RequireComponent (typeof(Rigidbody))]
public class PlayerMovement : MonoBehaviour
{
	public float speed = 6.0f;
	public LayerMask floorMask;

	private Animator _anim;
	private Rigidbody _rg;
	private float _camRayLength = 100.0f;

	void Awake ()
	{
		_anim = GetComponent<Animator> ();
		_rg = GetComponent<Rigidbody> ();
	}

	void FixedUpdate()
	{
		float h = Input.GetAxisRaw ("Horizontal");
		float v = Input.GetAxisRaw ("Vertical");

		Move (h, v);
		Rotate ();
		Animating (h, v);
	}

	private void Move(float h, float v)
	{
		Vector3 movement = new Vector3 (h, 0.0f, v);
		movement = movement.normalized * speed * Time.deltaTime;
		_rg.MovePosition (transform.position + movement);
	}

	private void Rotate()
	{
		Ray camRay = Camera.main.ScreenPointToRay (Input.mousePosition);

		RaycastHit floorHit;

		if (Physics.Raycast(camRay, out floorHit, _camRayLength, floorMask))
		{
			Vector3 playerToMouse = floorHit.point - transform.position;
			//playerToMouse.y = 0f;

			Quaternion newRotation = Quaternion.LookRotation (playerToMouse);
			_rg.MoveRotation (newRotation);
		}
	}

	private void Animating (float h, float v)
	{
		bool walking = ( h != 0 || v != 0 );
		_anim.SetBool ("IsWalking", walking);
	}
}
