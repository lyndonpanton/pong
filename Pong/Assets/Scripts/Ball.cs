using System.Collections;
using System.Collections.Generic;
using TMPro;
using Unity.VisualScripting;
using UnityEditor;
using UnityEngine;

public class Ball : MonoBehaviour
{
    public GameObject ballPrefab;
    public Rigidbody2D rb2d;
    public const int speed = 6;
    public bool isDead = false;

    // Start is called before the first frame update
    void Start()
    {
        rb2d = GetComponent<Rigidbody2D>();
        StartMoving();
    }

    void OnCollisionEnter2D(Collision2D collision)
    {
        float xVelocity = rb2d.velocity.x;
        Vector2 newVelocity = new Vector2(xVelocity, rb2d.velocity.y);

        rb2d.velocity = newVelocity;
    }

    void OnTriggerExit2D(Collider2D collision)
    {
        if (gameObject.transform.position.x < 0)
        {
            GameManager.IncrementRightScore(1);
        }
        else
        {
            GameManager.IncrementLeftScore(1);
        }

        BallSpawner.SpawnBall(gameObject);
        isDead = true;
        Destroy(gameObject);
    }

    private void StartMoving()
    {
        float x = Random.Range(0, 2) == 0 ? -1 : 1;
        //float yDirection = Random.Range(0, Mathf.PI);
        float y = Random.Range(0, 2) == 0 ? -1 : 1;
        //rb2d.AddForce(
        //    new Vector2(xDirection, yDirection) * speed,
        //    ForceMode2D.Impulse
        //);

        //rb2d.velocity = Random.onUnitSphere * speed;
        //rb2d.velocity = Random.onUnitSphere * speed * new Vector2 (xDirection, yDirection);
        rb2d.velocity = new Vector2(x * speed, y * speed);
    }
}
