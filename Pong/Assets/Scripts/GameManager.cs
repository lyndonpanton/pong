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

        int newScore = (int.Parse(leftScoreObject.text) + 1);
        leftScoreObject.text = newScore.ToString();

        if (newScore == 10)
        {
            // this player wins, play again?
            Debug.Log("Player 1 wins");
        }
    }

    public static void IncrementRightScore(int score)
    {
        GameObject canvas = GameObject.Find("Canvas");
        rightScoreObject = canvas.GetComponentsInChildren<TextMeshProUGUI>()[1];

        int newScore = (int.Parse(rightScoreObject.text) + 1);
        rightScoreObject.text = newScore.ToString();

        if (newScore == 10)
        {
            // this player wins, play again?
            Debug.Log("Player 2 wins");
        }
    }
}
