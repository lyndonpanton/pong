#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{

public:
	std::string m_name;
	int* m_position;
	int* m_dimensions;
	int* m_colour;

	Player();
	Player(const Player&);
	Player(std::string, int*, int*, int*);
	~Player();

	std::string get_name() const;
	int* get_position() const;
	int* get_dimensions() const;
	int* get_colour() const;

	void set_name(std::string);
	void set_position(int*);
	void set_position(int, int);
	void set_dimensions(int*);
	void set_dimensions(int, int);
	void set_colour(int*);
	void set_colour(int, int, int);
};

#endif PLAYER_H
