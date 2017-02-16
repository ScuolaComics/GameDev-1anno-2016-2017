using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Patroller : MonoBehaviour 
{
	public Transform _patrolTranform;
	public GameObject _target;

	public float _speed = 10.0f;

	public bool _smoothMovement;

	private Vector3 _initialPosition;
	private Vector3 _destination;

	private float _startTime;
	private float _journeyLength;

	// Use this for initialization
	void Start ()
	{
		_initialPosition = _patrolTranform.position;
		_destination = _target.transform.position;
		_startTime = Time.time;
		_journeyLength = Vector3.Distance(_destination, _initialPosition);

		_target.SetActive(false);

	}
	
	// Update is called once per frame
	void Update () 
	{
		float distanceCovered = (Time.time - _startTime) * _speed;
		float fractionJourney = distanceCovered / _journeyLength;

		if (_smoothMovement)
		{
			fractionJourney = Mathf.SmoothStep(0f, 1f, fractionJourney);
		}

		_patrolTranform.position = Vector3.Lerp(_initialPosition, _destination, fractionJourney);

		if (_patrolTranform.position == _destination)
		{
			Vector3 tempPosition = _initialPosition;
			_initialPosition = _destination;
			_destination = tempPosition;

			_startTime = Time.time;
		}
	}
}
