#pragma once

#ifndef UI_H
#define UI_H

#include <iostream>

class UI
{
	int* m_player_one_score_position;
	int* m_player_two_score_position;
	int* m_pause_message_position;
public:
	/* General ***************************************************************/
	UI();
	UI(const UI&);
	UI(int*, int*, int*);
	UI(int, int, int, int, int, int);
	~UI();

	/* Getter ****************************************************************/
	int* get_player_one_score_position() const;
	int* get_player_two_score_position() const;
	int* get_pause_message_position() const;

	/* Setter ****************************************************************/
	void set_player_one_score_position(int*);
	void set_player_one_score_position(int, int);
	void set_player_two_score_position(int*);
	void set_player_two_score_position(int, int);
	void set_pause_message_position(int*);
	void set_pause_message_position(int, int);
};

#endif UI_H
