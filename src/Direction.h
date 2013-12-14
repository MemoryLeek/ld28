#ifndef DIRECTION_H
#define DIRECTION_H

#include "BinaryStream.h"

struct Direction
{
	enum Value
	{
		None,
		Left,
		Right,
		Top,
		Bottom
	};
};

BinaryStream &operator >>(BinaryStream &stream, Direction::Value &direction);

#endif // DIRECTION_H
