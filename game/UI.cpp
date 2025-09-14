#include "UI.h"

/* General *******************************************************************/
UI::UI()
	: m_player_one_score_position(new int[2] { 100, 40 })
	, m_player_two_score_position(new int[2] { 940, 40 })
	, m_pause_message_position(new int[2] { 185, 90 })
{

}

UI::UI(const UI& ui)
	: m_player_one_score_position(ui.get_player_one_score_position())
	, m_player_two_score_position(ui.get_player_two_score_position())
	, m_pause_message_position(ui.get_pause_message_position())
{

}

UI::UI(
	int* player_one_score_position,
	int* player_two_score_position,
	int* pause_message_position
)
	: m_player_one_score_position(player_one_score_position)
	, m_player_two_score_position(player_two_score_position)
	, m_pause_message_position(pause_message_position)
{

}

UI::UI(
	int player_one_score_position_x,
	int player_one_score_position_y,
	int player_two_score_position_x,
	int player_two_score_position_y,
	int pause_message_position_x,
	int pause_message_position_y
)
	: m_player_one_score_position(new int[2] {
		player_one_score_position_x, player_one_score_position_y 
	})
	, m_player_two_score_position(new int[2] {
		player_two_score_position_x, player_two_score_position_y	
	})
	, m_pause_message_position(new int[2] {
		pause_message_position_x, pause_message_position_y
	})
{

}

UI::~UI()
{
	std::cout << "UI was destroyed" << std::endl;
}

/* Getter *******************************************************************/

int* UI::get_player_one_score_position() const
{
	return m_player_one_score_position;
}

int* UI::get_player_two_score_position() const
{
	return m_player_two_score_position;
}

int* UI::get_pause_message_position() const
{
	return m_pause_message_position;
}

/* Setter *******************************************************************/

void UI::set_player_one_score_position(int* position)
{
	m_player_one_score_position = position;
}

void UI::set_player_one_score_position(int x, int y)
{
	m_player_one_score_position[0] = x;
	m_player_one_score_position[1] = y;
}

void UI::set_player_two_score_position(int* position)
{
	m_player_two_score_position = position;
}

void UI::set_player_two_score_position(int x, int y)
{
	m_player_two_score_position[0] = x;
	m_player_two_score_position[1] = y;
}

void UI::set_pause_message_position(int* position)
{
	m_pause_message_position = position;
}

void UI::set_pause_message_position(int x, int y)
{
	m_pause_message_position[0] = x;
	m_pause_message_position[1] = y;
}
