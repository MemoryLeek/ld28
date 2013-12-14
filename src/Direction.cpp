#include "Direction.h"

BinaryStream &operator >>(BinaryStream &stream, Direction::Value &direction)
{
	int value = 0;

	stream >> value;
	direction = (Direction::Value)value;

	return stream;
}
