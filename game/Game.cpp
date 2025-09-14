#include "Game.h"

/* General *******************************************************************/
Game::Game()
	: m_target_score(10)
	, m_font_ui_size(80)
	, m_font_win_screen_size(32)
	, m_pause_message_offset(new int[2] { 90, 50 })
	, m_pause_message("CONTINUE?")
{

}

Game::Game(const Game& game)
	: m_target_score(game.get_target_score())
	, m_font_ui_size(game.get_font_ui_size())
	, m_font_win_screen_size(game.get_font_win_screen_size())
	, m_pause_message_offset(game.get_pause_message_offset())
	, m_pause_message(game.get_pause_message())
{

}

Game::Game(
	int target_score,
	int font_ui_size,
	int font_win_screen_size,
	int* pause_message_offset,
	std::string pause_message
)
	: m_target_score(target_score)
	, m_font_ui_size(font_ui_size)
	, m_font_win_screen_size(font_win_screen_size)
	, m_pause_message_offset(pause_message_offset)
	, m_pause_message(pause_message)
{

}

Game::~Game()
{
	std::cout << "Game has ended" << std::endl;
}

/* Getters *******************************************************************/
int Game::get_font_ui_size() const
{
	return m_font_ui_size;
}

int Game::get_font_win_screen_size() const
{
	return m_font_win_screen_size;
}

bool Game::get_is_complete() const
{
	return m_is_complete;
}

bool Game::get_is_paused() const
{
	return m_is_paused;
}

std::string Game::get_pause_message() const
{
	return m_pause_message;
}

int* Game::get_pause_message_offset() const
{
	return m_pause_message_offset;
}

int Game::get_target_score() const
{
	return m_target_score;
}

PlayerType Game::get_winner() const
{
	return m_winner;
}

/* Setters *******************************************************************/
void Game::set_font_ui_size(int font_size)
{
	m_font_ui_size = font_size;
}

void Game::set_font_win_screen_size(int font_size)
{
	m_font_win_screen_size = font_size;
}

void Game::set_is_complete(bool is_complete)
{
	m_is_complete = is_complete;
}

void Game::set_is_paused(bool is_paused)
{
	m_is_paused = is_paused;
}

void Game::set_pause_message(std::string pause_message)
{
	m_pause_message = pause_message;
}

void Game::set_pause_message_offset(int* offset)
{
	m_pause_message_offset = offset;
}

void Game::set_pause_message_offset(int offset_x, int offset_y)
{
	m_pause_message_offset[0] = offset_x;
	m_pause_message_offset[1] = offset_y;
}

void Game::set_target_score(int target_score)
{
	m_target_score = target_score;
}

void Game::set_winner(PlayerType winner)
{
	m_winner = winner;
}

/* Other *********************************************************************/

void Game::finish(Player& player)
{
	set_is_complete(true);
	set_winner(player.get_player_type());
}

void Game::reset()
{
	set_is_complete(false);
	set_is_paused(false);
	set_winner(PlayerType::NONE);
}
