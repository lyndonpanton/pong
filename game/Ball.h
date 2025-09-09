#pragma once

#ifndef BALL_H
#define BALL_H

#include <iostream>

class Ball
{

public:
	int* m_colour;
	int m_point_count;
	int* m_position;
	int m_radius;
	float* m_velocity;

	Ball();
	Ball(const Ball&);
	Ball(int*, int, int, float*, int*);
	~Ball();

	int* get_colour() const;
	int get_point_count() const;
	int* get_position() const;
	int get_radius() const;
	float* get_velocity() const;

	void set_colour(int*);
	void set_point_count(int);
	void set_position(int*);
	void set_radius(int);
	void set_velocity(float*);
};

#endif BALL_H;
