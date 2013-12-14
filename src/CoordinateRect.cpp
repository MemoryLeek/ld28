#include "CoordinateRect.h"

CoordinateRect::CoordinateRect(const int x, const int y, const int width, const int height)
	: m_x(x)
	, m_y(y)
	, m_width(width)
	, m_height(height)
{

}

Coordinate CoordinateRect::topLeft() const
{
	return Coordinate(m_x, m_y);
}

Coordinate CoordinateRect::topRight() const
{
	return Coordinate(m_x + m_width, m_y);
}

Coordinate CoordinateRect::bottomLeft() const
{
	return Coordinate(m_x, m_y + m_height);
}

Coordinate CoordinateRect::bottomRight() const
{
	return Coordinate(m_x + m_width, m_y + m_height);
}
