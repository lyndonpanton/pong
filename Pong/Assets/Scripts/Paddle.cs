using System.Collections;
using System.Collections.Generic;
using System.Runtime.ConstrainedExecution;
using UnityEngine;

class Paddle : MonoBehaviour
{
    public const int speed = 5;
    public Rigidbody2D rb2d;

    void Start()
    {
        rb2d = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        Vector2 position = transform.position;

        if (Input.GetKey(KeyCode.W))
        {
            Debug.Log("The up key is being pressed");
            position.y += Time.deltaTime * speed;
        } else if (Input.GetKey(KeyCode.S))
        {
            Debug.Log("The down key is being pressed");
            position.y -= Time.deltaTime * speed;
        }

        transform.position = position;
    }
}