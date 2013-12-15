#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "Direction.h"
#include "BinaryStream.h"

class MapObject
{
	friend BinaryStream &operator >>(BinaryStream &stream, MapObject &object);

	public:
		MapObject();

		int id() const;
		int direction() const;

	private:
		int m_id;
		int m_direction;
};

#endif // MAPOBJECT_H
