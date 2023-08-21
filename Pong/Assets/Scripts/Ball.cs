using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using UnityEngine.Rendering;

public class Ball : MonoBehaviour
{
    public Rigidbody2D rb2d;
    public const int speed = 50;
    // Start is called before the first frame update
    void Start()
    {
        float xDirection = Random.Range(0, Mathf.PI) * speed;
        float yDirection = Random.Range(0, Mathf.PI) * speed;

        if (Random.Range(0, 2) == 0)
        {
            xDirection *= -1;
        }

        if (Random.Range(0, 2) == 0)
        {
            yDirection *= -1;
        }

        rb2d = GetComponent<Rigidbody2D>();
        rb2d.velocity = new Vector2(
            xDirection,
            yDirection
        ).normalized;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
