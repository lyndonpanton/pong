using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SoundManagerGame : MonoBehaviour
{
    //public AudioSource source;
    public AudioClip sfx_hit, sfx_point, sfx_win;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }

    public void PlayHitSoundEffect()
    {
        AudioSource source = GetComponent<AudioSource>();
        source.clip = sfx_hit;
        source.Play();
    }

    public void PlayPointSoundEffect()
    {
        AudioSource source = GetComponent<AudioSource>();
        source.clip = sfx_point;
        source.Play();
    }

    public void PlayWinSoundEffect()
    {
        AudioSource source = GetComponent<AudioSource>();
        source.clip = sfx_win;
        source.Play();
    }
}
