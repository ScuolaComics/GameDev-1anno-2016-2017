using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraFollow : MonoBehaviour 
{
	public Transform playerTransform;
	public float smoothing = 5f;

	private Vector3 _offset;

	// Use this for initialization
	void Start () 
	{
		if (playerTransform != null) 
		{
			_offset = transform.position - playerTransform.position;
		}
	}
	
	// Update is called once per frame
	void FixedUpdate () 
	{
		if (playerTransform != null) 
		{
			Vector3 newCameraPosition = playerTransform.position + _offset;
			transform.position = Vector3.Lerp (transform.position, newCameraPosition, smoothing * Time.deltaTime);
		}
	}
}
