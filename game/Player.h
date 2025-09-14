#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "PlayerType.h"

class Player
{

public:
	int* m_colour;
	int* m_dimension;
	std::string m_name;
	enum PlayerType m_player_type;
	int* m_position;
	int* m_position_initial;
	int m_score = 0;
	int m_speed;

	bool m_is_moving_up = false;
	bool m_is_moving_down = false;

	Player();
	Player(const Player&);
	Player(PlayerType, std::string, int*, int*, int*, int);
	~Player();

	int* get_colour() const;
	int* get_dimension() const;
	std::string get_name() const;
	const PlayerType get_player_type() const;
	int* get_position() const;
	int* get_position_initial() const;
	int get_score() const;
	int get_speed() const;

	void set_colour(int*);
	void set_colour(int, int, int);
	void set_dimension(int*);
	void set_dimension(int, int);
	void set_name(std::string);
	void set_player_type(PlayerType player_type);
	void set_position(int*);
	void set_position(int, int);
	void set_position_initial(int*);
	void set_position_initial(int, int);
	void set_score(int);
	void set_speed(int);

	void move(bool);
	void reset();
	void update(int);
};

#endif PLAYER_H
