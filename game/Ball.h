#pragma once

#ifndef BALL_H
#define BALL_H

#include <iostream>

#include "Player.h"

class Ball
{

public:
	int* m_colour;
	int m_point_count;
	int* m_position;
	int* m_position_initial;
	int m_radius;
	float* m_velocity;
	float* m_velocity_initial;
	bool m_is_moving = false;

	Ball();
	Ball(const Ball&);
	Ball(int*, int, int, float*, int*);
	~Ball();

	int* get_colour() const;
	int get_point_count() const;
	int* get_position() const;
	int* get_position_initial() const;
	int get_radius() const;
	float* get_velocity() const;
	float* get_velocity_initial() const;
	bool get_is_moving() const;

	void set_colour(int*);
	void set_point_count(int);
	void set_position(int*);
	void set_position_initial(int*);
	void set_radius(int);
	void set_velocity(float*);
	void set_velocity_initial(float*);
	void set_is_moving(bool);

	void bounce(); // overlap with top or bottom of paddle
	void collide(Player&); // overlap with "front" of paddle
	void reflect(); // overlap with top or bottom window edge
	void reset();
	void reset(Player&); // overlap with left or right window edge
	void update();
};

#endif BALL_H;
