#pragma once

#ifndef GAME_H
#define GAME_H

#include <iostream>

class Game
{
	int m_target_score = 10;
	bool m_is_paused = false;
public:
	Game();
	Game(const Game&);
	Game(int);
	~Game();

	bool get_is_paused() const;
	int get_target_score() const;

	void set_is_paused(bool);
	void set_target_score(int);
};

#endif GAME_H
