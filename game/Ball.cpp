#include "Ball.h"

/* General *******************************************************************/
Ball::Ball()
	: m_position(new int[2] { 0, 0 })
	, m_position_initial(new int[2] { m_position[0], m_position[1]})
	, m_radius(30)
	, m_point_count(16)
	, m_velocity(new float[2] { -4, 4 })
	, m_velocity_initial(new float[2] { m_velocity[0], m_velocity[1] })
	, m_colour(new int[3] { 255, 255, 255 })
{

}

Ball::Ball(const Ball& ball)
	: m_position(ball.get_position())
	, m_position_initial(new int[2] { m_position[0], m_position[1]})
	, m_radius(ball.get_radius())
	, m_point_count(ball.get_point_count())
	, m_velocity(ball.get_velocity())
	, m_velocity_initial(ball.get_velocity_initial())
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
	, m_position_initial(new int[2] { m_position[0], m_position[1] })
	, m_radius(radius)
	, m_point_count(point_count)
	, m_velocity(velocity)
	, m_velocity_initial(new float[2] { m_velocity[0], m_velocity[1] })
	, m_colour(colour)
{

}

Ball::~Ball()
{
	std::cout << "Ball was destroyed at position (" << get_position()[0] << ", "
		<< get_position()[1] << ")" << std::endl;
}

/* Getters *******************************************************************/
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

int* Ball::get_position_initial() const
{
	return m_position_initial;
}

int Ball::get_radius() const
{
	return m_radius;
}

float* Ball::get_velocity() const
{
	return m_velocity;
}

float* Ball::get_velocity_initial() const
{
	return m_velocity_initial;
}

bool Ball::get_is_moving() const
{
	return m_is_moving;
}

/* Setters *******************************************************************/
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

void Ball::set_position_initial(int* position)
{
	m_position_initial = position;
}

void Ball::set_radius(int radius)
{
	m_radius = radius;
}

void Ball::set_velocity(float* velocity)
{
	m_velocity = velocity;
}

void Ball::set_velocity_initial(float* velocity)
{
	m_velocity_initial = velocity;
}

void Ball::set_is_moving(bool is_moving)
{
	m_is_moving = is_moving;
}

/* Other *********************************************************************/
void Ball::reset()
{
	set_position(m_position_initial);
	// change to calculate new random velocity instead
	set_velocity(m_velocity_initial);

}
