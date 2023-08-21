using System.Collections;
using System.Collections.Generic;
using System.Runtime.ConstrainedExecution;
using UnityEngine;
using UnityEngine.UIElements;

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

        if (gameObject.CompareTag("player one"))
        {
            MovePaddle(KeyCode.W, KeyCode.S);
        } else if (gameObject.CompareTag("player two"))
        {
            MovePaddle(KeyCode.UpArrow, KeyCode.DownArrow);
        }
    }

    void MovePaddle(KeyCode upKey, KeyCode downKey)
    {
        Vector2 position = transform.position;

        if (Input.GetKey(upKey))
        {
            position.y += Time.deltaTime * speed;
        }
        else if (Input.GetKey(downKey))
        {
            position.y -= Time.deltaTime * speed;
        }

        transform.position = position;
    }
}