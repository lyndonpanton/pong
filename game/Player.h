#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{

public:
	const char* m_name;
	int* m_position;
	int* m_dimensions;
	int* m_colour;

	bool is_moving_up;
	bool is_moving_down;
	int speed = 5;

	Player();
	Player(const Player&);
	Player(const char*, int*, int*, int*);
	~Player();

	const char* get_name() const;
	int* get_position() const;
	int* get_dimensions() const;
	int* get_colour() const;

	void set_name(const char*);
	void set_position(int*);
	void set_position(int, int);
	void set_dimensions(int*);
	void set_dimensions(int, int);
	void set_colour(int*);
	void set_colour(int, int, int);
};

#endif PLAYER_H
