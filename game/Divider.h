#pragma once

#ifndef DIVIDER_H
#define DIVIDER_H

#include <iostream>

class Divider
{
	int* m_dimension;
	int m_gap;
	int* m_colour;
public:
	/* General ***************************************************************/
	Divider();
	Divider(const Divider&);
	Divider(int*, int, int*);
	Divider(int, int, int, int, int, int);
	~Divider();

	/* Getter ****************************************************************/
	int* get_colour() const;
	int* get_dimension() const;
	int get_gap() const;

	/* Setter ****************************************************************/
	void set_colour(int*);
	void set_colour(int, int, int);
	void set_dimension(int*);
	void set_dimension(int, int);
	void set_gap(int);
};

#endif DIVIDER_H
