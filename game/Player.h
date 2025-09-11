#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "PlayerType.h"

class Player
{

public:
	enum PlayerType m_player_type;
	const char* m_name;
	int* m_position;
	int* m_dimensions;
	int* m_colour;
	int m_score = 0;

	bool is_moving_up = false;
	bool is_moving_down = false;
	float speed = 5.0f;

	Player();
	Player(const Player&);
	Player(PlayerType, const char*, int*, int*, int*);
	~Player();

	const PlayerType get_player_type() const;
	const char* get_name() const;
	int* get_position() const;
	int* get_dimensions() const;
	int* get_colour() const;
	int get_score() const;

	void set_player_type(PlayerType player_type);
	void set_name(const char*);
	void set_position(int*);
	void set_position(int, int);
	void set_dimensions(int*);
	void set_dimensions(int, int);
	void set_colour(int*);
	void set_colour(int, int, int);
	void set_score(int);
};

#endif PLAYER_H
