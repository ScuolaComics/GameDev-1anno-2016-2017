using UnityEngine;
using System.Collections;

public class Fighter : Target 
{
	public float range;
	public float speed;
	public float fireRate;
	public float projectileSpeed;
	public int projectileDamage;
	public GameObject shot;
	public Transform shotSpawn;

	private Rigidbody rb;
	private AudioSource fireSFX;

	private Target currentTarget;
	private float nextFire;
	private Quaternion moveRotation;

	protected override void Awake()
	{
		base.Awake();
		rb = GetComponent<Rigidbody>();
		fireSFX = GetComponent<AudioSource>();
		moveRotation = rb.rotation;
	}
	
	// Update is called once per frame
	void Update () 
	{
//		if (currentTarget == null)
//		{
//			currentTarget = CheckForEnemies();
//		}
//		if (currentTarget != null)
//		{
//			FaceOpponent();
//			if (Time.time > nextFire)
//			{
//				nextFire = Time.time + fireRate;
//				Fire();
//			}
//		}
//		else
//		{
//			MoveForward();
//		}
	}

	public void Unleash()
	{
		MoveForward();
	}

	void FaceOpponent()
	{
		transform.LookAt(currentTarget.gameObject.transform.position);
		rb.velocity = Vector3.zero;
	}

	void MoveForward()
	{
		rb.MoveRotation(moveRotation);
		rb.velocity = transform.forward * speed;
	}
		
	Target CheckForEnemies()
	{
		Collider[] targetColliders = Physics.OverlapSphere(transform.position, range);
		foreach (Collider targetCollider in targetColliders)
		{
			Target possibleTarget = targetCollider.GetComponent<Target>();
			if (possibleTarget != null && possibleTarget.owner.index != owner.index)
			{
				return possibleTarget;
			}
		}
		return null;
	}

	void OnTriggerExit(Collider other)
	{
		if (other.CompareTag("Boundary"))
		{
			Destroy(gameObject);
		}
	}

	void Fire ()
	{
		GameObject shotInstance = Instantiate(shot, shotSpawn.position, shotSpawn.rotation) as GameObject;
		Projectile projectileScript = shotInstance.GetComponent<Projectile>();
		projectileScript.damage = projectileDamage;
		projectileScript.speed = projectileSpeed;
		projectileScript.owner = owner;
		fireSFX.Play();
	}
}
