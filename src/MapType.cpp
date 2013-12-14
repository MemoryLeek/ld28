#include "MapType.h"

BinaryStream &operator >>(BinaryStream &stream, MapType::Value &direction)
{
	int value = 0;

	stream >> value;
	direction = (MapType::Value)value;

	return stream;
}
