#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>

#include <boost/operators.hpp>

class Point: boost::less_than_comparable<Point,
	boost::equality_comparable<Point>,
	boost::addable<Point, 
	boost::subtractable<Point>>>
{
public:
	explicit Point(int x = 0, int y = 0, int z = 0):
		m_x(x), m_y(y), m_z(z)
		{}

	void print() const
	{ std::cout << m_x << ", " << m_y << ", " << m_z << std::endl; }

	friend bool operator<(const Point& l, const Point& r)
	{
		return ((l.m_x * l.m_x + l.m_y * l.m_y + l.m_z * l.m_z) < 
			(r.m_x * r.m_x + r.m_y * r.m_y + r.m_z * r.m_z));
	}

	friend bool operator==(const Point& l, const Point& r)
	{
		return (l.m_x == r.m_x && l.m_y == r.m_y && l.m_z == r.m_z);
	}

	Point& operator+=(const Point& r)
	{
		m_x += r.m_x;
		m_y += r.m_y;
		m_z += r.m_z;
		return *this;
	}

	Point& operator-=(const Point& r)
	{
		m_x -= r.m_x;
		m_y -= r.m_y;
		m_z -= r.m_z;
		return *this;
	}

private:
	int m_x, m_y, m_z;
};

const Point operator+(const Point& l, const Point& r)
{
	return Point(l) += r;
}

const Point operator-(const Point& l, const Point& r)
{
	return Point(l) -= r;
}

#endif
