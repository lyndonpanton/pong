#include "Player.h"

/* General *******************************************************************/
Player::Player()
	: m_player_type(PlayerType::ONE)
	, m_name("???")
	, m_position(new int[2] { 100, 100 })
	, m_position_initial(m_position)
	, m_dimensions(new int[2] { 20, 80 })
	, m_colour(new int[3] { 127, 127, 127 })
{
}

Player::Player(const Player& player)
	: m_player_type(player.get_player_type())
	, m_name(player.get_name())
	, m_position(player.get_position())
	, m_dimensions(player.get_dimensions())
	, m_colour(player.get_colour())
{

}

Player::Player(
	PlayerType player_type,
	const char* name,
	int* position,
	int* dimensions,
	int* colours
)
	: m_player_type(player_type)
	, m_name(name)
	, m_position(position)
	, m_position_initial(m_position)
	, m_dimensions(dimensions)
	, m_colour(colours)
{

}

Player::~Player()
{
	std::cout << "Player: " << m_name << " has been destroyed" << std::endl;
}

/* Getters *******************************************************************/
const PlayerType Player::get_player_type() const
{
	return m_player_type;
}

const char* Player::get_name() const
{
	return m_name;
}

int* Player::get_position() const
{
	return m_position;
}

int* Player::get_position_initial() const
{
	return m_position_initial;
}

int* Player::get_dimensions() const
{
	return m_dimensions;
}

int* Player::get_colour() const
{
	return m_colour;
}

int Player::get_score() const {
	return m_score;
}

float Player::get_speed() const
{
	return m_speed;
}

/* Setters *******************************************************************/
void Player::set_player_type(PlayerType player_type)
{
	m_player_type = player_type;
}

void Player::set_name(const char* name)
{
	m_name = name;
}

void Player::set_position(int* position)
{
	m_position = position;
}

void Player::set_position(int x, int y)
{
	m_position[0] = x;
	m_position[1] = y;
}

void Player::set_position_initial(int* position)
{
	m_position_initial = position;
}

void Player::set_position_initial(int x, int y)
{
	m_position_initial[0] = x;
	m_position_initial[1] = y;
}

void Player::set_dimensions(int* dimensions)
{
	m_dimensions = dimensions;
}

void Player::set_dimensions(int width, int height)
{
	m_dimensions[0] = width;
	m_dimensions[1] = height;
}

void Player::set_colour(int* colour)
{
	m_colour = colour;
}

void Player::set_colour(int red, int green, int blue)
{
	m_colour[0] = red;
	m_colour[1] = green;
	m_colour[2] = blue;
}

void Player::set_score(int score)
{
	m_score = score;
}

void Player::set_speed(float speed)
{
	m_speed = speed;
}

/* Other *********************************************************************/
void Player::reset()
{
	m_position = new int[2] { m_position_initial[0], m_position_initial[1] };
	m_score = 0;
}
