using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using UnityEngine.Rendering;

public class Ball : MonoBehaviour
{
    public Rigidbody2D rb2d;
    public const int speed = 8;
    // Start is called before the first frame update
    void Start()
    {
        float xDirection = Random.Range(0, Mathf.PI);
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

        rb2d.velocity = Random.onUnitSphere * speed;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
