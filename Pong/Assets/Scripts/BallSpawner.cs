using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BallSpawner : MonoBehaviour
{
    public GameObject ballPrefab;

    // Start is called before the first frame update
    void Start()
    {
        SpawnBall();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void SpawnBall()
    {
        Instantiate(
            ballPrefab,
            new Vector3(0, 0, 0),
            Quaternion.identity
        );
    }
}
