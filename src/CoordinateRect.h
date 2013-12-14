#ifndef COORDINATERECT_H
#define COORDINATERECT_H

#include "Room.h"

class CoordinateRect
{
	public:
		CoordinateRect(const int x, const int y, const int width, const int height);

		Coordinate topLeft() const;
		Coordinate topRight() const;
		Coordinate bottomLeft() const;
		Coordinate bottomRight() const;

	private:
		int m_x;
		int m_y;
		int m_width;
		int m_height;
};

#endif // COORDINATERECT_H
