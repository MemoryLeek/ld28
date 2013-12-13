#ifndef ROOMOBJECT_H
#define ROOMOBJECT_H

#include <map>
#include <utility>

#include "Tile.h"

using Coordinate = std::pair<int, int>;

const int TILE_SIZE = 32;

class RoomObject
{
	friend BinaryStream &operator >>(BinaryStream &stream, RoomObject &room);

	public:
		RoomObject();

		std::map<Coordinate, Tile> tiles() const;

	private:
		std::map<Coordinate, Tile> m_tiles;
};

#endif // ROOMOBJECT_H
