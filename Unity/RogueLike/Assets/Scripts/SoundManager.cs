using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundManager : MonoBehaviour 
{
	public AudioSource efxSource;
	public AudioSource musicSource;
	public static SoundManager instance = null;

	public float lowPitchRange = .95f;
	public float highPitchRange = 1.05f;

	void Awake ()
	{
		if (instance == null) 
		{
			instance = this;
		}
		else
		{
			Destroy (gameObject);
		}
		DontDestroyOnLoad (gameObject);
	}

	public void PlaySingle(AudioClip clip)
	{
		this.efxSource.pitch = 1.0f;
		this.efxSource.clip = clip;
		this.efxSource.Play ();
	}

	public void RandomizeSfx(params AudioClip[] clip)
	{
		int randomIndex = Random.Range (0, clip.Length);
		float randomPitch = Random.Range (lowPitchRange, highPitchRange);

		this.efxSource.pitch = randomPitch;
		this.efxSource.clip = clip [randomIndex];
		this.efxSource.Play ();
	}

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
