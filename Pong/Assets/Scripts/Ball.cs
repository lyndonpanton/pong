using System.Collections;
using System.Collections.Generic;
using TMPro;
using Unity.VisualScripting;
using UnityEditor;
using UnityEngine;

public class Ball : MonoBehaviour
{
    [SerializeField]
    public GameObject ballPrefab;

    public Rigidbody2D rb2d;
    public const int speed = 3;
    public bool isDead = false;

    // Start is called before the first frame update
    void Start()
    {
        float xDirection = 1;
        float yDirection = Random.Range(0, Mathf.PI);

        if (Random.Range(0, 2) == 0)
        {
            xDirection *= -1;
        }

        if (Random.Range(0, 2) == 0)
        {
            yDirection *= -1;
        }

        rb2d = GetComponent<Rigidbody2D>();
        //rb2d.AddForce(
        //    new Vector2(xDirection, yDirection) * speed,
        //    ForceMode2D.Impulse
        //);

        //rb2d.velocity = Random.onUnitSphere * speed;
        //rb2d.velocity = Random.onUnitSphere * speed * new Vector2 (xDirection, yDirection);
        rb2d.velocity = new Vector2(xDirection, yDirection) * 3;
    }

    void OnCollisionEnter2D(Collision2D collision)
    {
        float xVelocity = rb2d.velocity.x;
        Vector2 newVelocity = new Vector2(xVelocity, rb2d.velocity.y);

        rb2d.velocity = newVelocity;
    }

    void OnTriggerExit2D(Collider2D collision)
    {
        // On the left
        if (gameObject.transform.position.x < 0)
        {
            GameManager.IncrementLeftScore(1);
        }
        else
        {
            GameManager.IncrementRightScore(1);
        }

        BallSpawner.SpawnBall(gameObject);
        isDead = true;
        Destroy(gameObject);
    }
}
