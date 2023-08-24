using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public static TextMeshProUGUI leftScoreObject;
    public static TextMeshProUGUI rightScoreObject;

    // Start is called before the first frame update
    void Start()
    {

    }

    public static void IncrementLeftScore(int score)
    {
        GameObject canvas = GameObject.Find("Canvas");
        leftScoreObject = canvas.GetComponentsInChildren<TextMeshProUGUI>()[0];
        leftScoreObject.text = (int.Parse(leftScoreObject.text) + 1).ToString();
    }

    public static void IncrementRightScore(int score)
    {
        GameObject canvas = GameObject.Find("Canvas");
        rightScoreObject = canvas.GetComponentsInChildren<TextMeshProUGUI>()[1];
        rightScoreObject.text = (int.Parse(rightScoreObject.text) + 1).ToString();
    }
}
