using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SoundManagerMenu : MonoBehaviour
{
    [SerializeField]
    Slider volumeSlider;

    private const string MUSIC_VOLUME_STRING = "musicVolume";

    // Start is called before the first frame update
    void Start()
    {
        // 1 = 100%
        if (!PlayerPrefs.HasKey(MUSIC_VOLUME_STRING))
        {
            PlayerPrefs.SetFloat(MUSIC_VOLUME_STRING, 1);
        }

        Load();
    }

    public void ChangeVolume()
    {
        AudioListener.volume = volumeSlider.value;
        Save();
    }

    private void Load()
    {
        volumeSlider.value = PlayerPrefs.GetFloat(MUSIC_VOLUME_STRING);
    }

    private void Save()
    {
        PlayerPrefs.SetFloat(MUSIC_VOLUME_STRING, volumeSlider.value);
    }
}
