using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEditor;
using UnityEngine;

public class BallSpawner : MonoBehaviour
{
    [SerializeField]
    public GameObject ballPrefab;

    // Start is called before the first frame update
    void Start()
    {
        SpawnBall(ballPrefab);
    }

    public static void SpawnBall(GameObject ball)
    {
        //GameObject ball;

        //ball = Instantiate<GameObject>(
        //    ballPrefab,
        //    new Vector3(0, 0, 0),
        //    Quaternion.identity
        //);

        Instantiate(
            ball,
            new Vector3(0, 0, 0),
            Quaternion.identity
        );
    }
}
