#include "Game.h"

/* General *******************************************************************/
Game::Game()
{

}

Game::Game(const Game& game)
	: m_is_paused(game.get_is_paused())
	, m_target_score(game.get_target_score())
{

}

Game::Game(int target_score)
	: m_target_score(target_score)
{

}

Game::~Game()
{
	std::cout << "Game has ended" << std::endl;
}

/* Getters *******************************************************************/
bool Game::get_is_paused() const
{
	return m_is_paused;
}

int Game::get_target_score() const
{
	return m_target_score;
}

/* Setters *******************************************************************/
void Game::set_is_paused(bool is_paused)
{
	m_is_paused = is_paused;
}

void Game::set_target_score(int target_score)
{
	m_target_score = target_score;
}
