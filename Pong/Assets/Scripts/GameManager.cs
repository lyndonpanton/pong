using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public TextMeshProUGUI leftScoreObject;
    public TextMeshProUGUI rightScoreObject;

    // Start is called before the first frame update
    void Start()
    {
        //gameObject.FindGameObjectWithTag("")
        GameObject canvas = GameObject.Find("Canvas");
        TextMeshProUGUI[] scoreObjects = canvas.GetComponentsInChildren<TextMeshProUGUI>();

        leftScoreObject = scoreObjects[0];
        rightScoreObject = scoreObjects[1];

        Debug.Log(leftScoreObject.name);
        Debug.Log(rightScoreObject.name);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void IncrementLeftScore()
    {


    }

    void IncrementRightScore()
    {

    }
}
