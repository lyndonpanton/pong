#include "Player.h"

/* General *******************************************************************/
Player::Player()
	: m_player_type(PlayerType::ONE)
	, m_name("???")
	, m_position(new int[2] { 100, 100 })
	, m_position_initial(m_position)
	, m_dimension(new int[2] { 20, 80 })
	, m_colour(new int[3] { 127, 127, 127 })
	, m_speed(4)
{
}

Player::Player(Player& player)
	: m_player_type(player.get_player_type())
	, m_position(player.get_position())
	, m_dimension(player.get_dimension())
	, m_colour(player.get_colour())
	, m_speed(player.get_speed())
{
	for (int i = 0; i < strlen(player.get_name()); i++)
	{
		m_name[i] = player.get_name()[i];

		if (i >= 25 - 1) break;
	}
}

Player::Player(
	PlayerType player_type,
	char* name,
	int* position,
	int* dimension,
	int* colours,
	int speed
)
	: m_player_type(player_type)
	, m_position(position)
	, m_position_initial(m_position)
	, m_dimension(dimension)
	, m_colour(colours)
	, m_speed(speed)
{
	for (int i = 0; i < strlen(name); i++)
	{
		m_name[i] = name[i];

		if (i >= 25 - 1) break;
	}
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

char* Player::get_name()
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

int* Player::get_dimension() const
{
	return m_dimension;
}

int* Player::get_colour() const
{
	return m_colour;
}

int Player::get_score() const {
	return m_score;
}

int Player::get_speed() const
{
	return m_speed;
}

/* Setters *******************************************************************/
void Player::set_player_type(PlayerType player_type)
{
	m_player_type = player_type;
}

void Player::set_name(char* name)
{
	for (int i = 0; i < strlen(name); i++)
	{
		m_name[i] = name[i];

		if (i >= 25 - 1) break;
	}
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

void Player::set_dimension(int* dimension)
{
	m_dimension = dimension;
}

void Player::set_dimension(int width, int height)
{
	m_dimension[0] = width;
	m_dimension[1] = height;
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

void Player::set_speed(int speed)
{
	m_speed = speed;
}

/* Other *********************************************************************/
void Player::move(bool is_moving_up)
{

}

void Player::reset()
{
	m_position = new int[2] { m_position_initial[0], m_position_initial[1] };
	m_score = 0;
}

void Player::update(int window_height)
{
	if (m_is_moving_up)
	{
		if (get_position()[1] > 0)
		{
			set_position(new int[2] {
				get_position()[0],
				get_position()[1] - (int)get_speed()
			});
		}
	}
	if (m_is_moving_down)
	{
		if (get_position()[1] + get_dimension()[1] < window_height)
		{
			set_position(new int[2] {
				get_position()[0],
				get_position()[1] + (int)get_speed()
			});
		}
	}
}
