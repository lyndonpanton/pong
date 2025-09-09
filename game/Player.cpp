#include "Player.h"

Player::Player()
{

}

Player::Player(const Player& player)
{

}

Player::Player(std::string name, int* position, int* dimensions, int* colours)
{

}

Player::~Player()
{
	std::cout << "Player: " << m_name << " has been destroyed" << std::endl;
}

std::string Player::get_name() const
{
	return m_name;
}

int* Player::get_position() const
{
	return m_position;
}

int* Player::get_dimensions() const
{
	return m_dimensions;
}

int* Player::get_colour() const
{
	return m_colour;
}

void Player::set_name(std::string name)
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
