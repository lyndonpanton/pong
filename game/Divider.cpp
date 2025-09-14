#include "Divider.h"

/* General *******************************************************************/
Divider::Divider()
	: m_dimension(new int[2] { 4, 40 })
	, m_gap(60)
	, m_colour(new int[3] { 255, 255, 255 })
{

}

Divider::Divider(const Divider& divider)
	: m_dimension(divider.get_dimension())
	, m_gap(divider.get_gap())
	, m_colour(divider.get_colour())
{

}

Divider::Divider(int* dimension, int gap, int* colour)
	: m_dimension(dimension)
	, m_gap(gap)
	, m_colour(colour)
{

}

Divider::Divider(
	int dimension_width,
	int dimension_height,
	int gap,
	int colour_red,
	int colour_green,
	int colour_blue
)
	: m_dimension(new int[2] { dimension_width, dimension_width })
	, m_gap(gap)
	, m_colour(new int[3] { colour_red, colour_green, colour_blue })
{

}

Divider::~Divider()
{
	std::cout << "Divider was destroyed" << std::endl;
}

/* Getter ********************************************************************/

int* Divider::get_colour() const
{
	return m_colour;
}

int* Divider::get_dimension() const
{
	return m_dimension;
}

int Divider::get_gap() const
{
	return m_gap;
}

/* Setter ********************************************************************/

void Divider::set_colour(int* colour)
{
	m_colour = colour;
}

void Divider::set_colour(int colour_red, int colour_green, int colour_blue)
{
	m_colour[0] = colour_red;
	m_colour[1] = colour_green;
	m_colour[2] = colour_blue;
}

void Divider::set_gap(int gap)
{
	m_gap = gap;
}

void Divider::set_dimension(int* dimension)
{
	m_dimension = dimension;
}

void Divider::set_dimension(int width, int height)
{
	m_dimension[0] = width;
	m_dimension[1] = height;
}
