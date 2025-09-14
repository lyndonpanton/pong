#pragma once

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "PlayerType.h"
#include "Player.h"

class Game
{
	int m_font_ui_size;
	int m_font_win_screen_size;
	bool m_is_paused = false;
	bool m_is_complete = false;
	std::string m_pause_message;
	int* m_pause_message_offset;
	int m_target_score = 10;
	PlayerType m_winner = PlayerType::NONE;
public:
	Game();
	Game(const Game&);
	Game(int, int, int, int*, std::string);
	~Game();

	int get_font_ui_size() const;
	int get_font_win_screen_size() const;
	bool get_is_complete() const;
	bool get_is_paused() const;
	std::string get_pause_message() const;
	int* get_pause_message_offset() const;
	int get_target_score() const;
	PlayerType get_winner() const;

	void set_font_ui_size(int);
	void set_font_win_screen_size(int);
	void set_is_complete(bool);
	void set_is_paused(bool);
	void set_pause_message(std::string);
	void set_pause_message_offset(int*);
	void set_pause_message_offset(int, int);
	void set_target_score(int);
	void set_winner(PlayerType);

	void finish(Player&);
	void reset();
};

#endif GAME_H
