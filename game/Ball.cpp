#include "Ball.h"

Ball::Ball()
	: m_position(new int[2] { 0, 0 })
	, m_radius(30)
	, m_point_count(16)
	, m_velocity(new float[2] { -4, 4 })
	, m_colour(new int[3] { 255, 255, 255 })
{

}

Ball::Ball(const Ball& ball)
	: m_position(ball.get_position())
	, m_radius(ball.get_radius())
	, m_point_count(ball.get_point_count())
	, m_velocity(ball.get_velocity())
	, m_colour(ball.get_colour())
{

}

Ball::Ball(
	int* position,
	int radius,
	int point_count,
	float* velocity,
	int* colour
)
	: m_position(position)
	, m_radius(radius)
	, m_point_count(point_count)
	, m_velocity(velocity)
	, m_colour(colour)
{

}

Ball::~Ball()
{
	std::cout << "Ball was destroyed at position (" << get_position()[0] << ", "
		<< get_position()[1] << ")" << std::endl;
}

int* Ball::get_colour() const
{
	return m_colour;
}

int Ball::get_point_count() const
{
	return m_point_count;
}

int* Ball::get_position() const
{
	return m_position;
}

int Ball::get_radius() const
{
	return m_radius;
}

float* Ball::get_velocity() const
{
	return m_velocity;
}

void Ball::set_colour(int* colour)
{
	m_colour = colour;
}

void Ball::set_point_count(int point_count)
{
	m_point_count = point_count;
}

void Ball::set_position(int* position)
{
	m_position = position;
}

void Ball::set_radius(int radius)
{
	m_radius = radius;
}

void Ball::set_velocity(float* velocity)
{
	m_velocity = velocity;
}
