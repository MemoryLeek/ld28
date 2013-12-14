#ifndef MAPTYPE_H
#define MAPTYPE_H

#include "BinaryStream.h"

struct MapType
{
	enum Value
	{
		Normal,
		Start,
		End
	};
};

BinaryStream &operator >>(BinaryStream &stream, MapType::Value &direction);

#endif // MAPTYPE_H
