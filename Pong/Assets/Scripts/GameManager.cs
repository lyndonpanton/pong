using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public static TextMeshProUGUI leftScoreObject;
    public static TextMeshProUGUI rightScoreObject;

    // Start is called before the first frame update
    void Start()
    {
        leftScoreObject = GameObject.Find("Scores")
            .GetComponentsInChildren<TextMeshProUGUI>()[0];
        rightScoreObject = GameObject.Find("Scores")
            .GetComponentsInChildren<TextMeshProUGUI>()[1];
    }

    public static void IncrementLeftScore(int score)
    {
        //GameObject canvas = GameObject.Find("Canvas");
        //leftScoreObject = canvas.GetComponentsInChildren<TextMeshProUGUI>()[0];
        leftScoreObject = GameObject.Find("Scores")
            .GetComponentsInChildren<TextMeshProUGUI>()[0];

        int newScore = (int.Parse(leftScoreObject.text) + 1);
        leftScoreObject.text = newScore.ToString();

        if (newScore == 10)
        {
            // this player wins, play again?
            Debug.Log("Player 1 wins");

            // TODO: Bring up play again/difficulty/main menu pop up
            Time.timeScale = 0;

            // Go to main menu
            //SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex - 1);
        }
    }

    public static void IncrementRightScore(int score)
    {
        //GameObject canvas = GameObject.Find("Canvas");
        //rightScoreObject = canvas.GetComponentsInChildren<TextMeshProUGUI>()[1];
        rightScoreObject = GameObject.Find("Scores")
            .GetComponentsInChildren<TextMeshProUGUI>()[1];

        int newScore = (int.Parse(rightScoreObject.text) + 1);
        rightScoreObject.text = newScore.ToString();

        if (newScore == 10)
        {
            // this player wins, play again?
            Debug.Log("Player 2 wins");

            Time.timeScale = 0;

            /* TODO:
             * 
             * Bring up play again/change difficulty/main menu pop up
             * State which player won
             * Add options to: play again, change difficulty and go to the main menu
             * 
             */

            //GameObject.Find("PauseMenu").SetActive(false);
            //GameObject.Find("GameOverMenu").SetActive(true);
            

            // Go to main menu
            //SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex - 1);
        }
    }
}
