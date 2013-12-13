#ifndef ROOMOBJECT_H
#define ROOMOBJECT_H

#include <QHash>

#include "TileObject.h"

using Coordinate = QPair<unsigned int, unsigned int>;

class RoomObject
{
	public:
		RoomObject();

		void addTile(Coordinate coordinate, const Tile &tile);

	private:
		friend QDataStream &operator <<(QDataStream &stream, const RoomObject &room);

		QHash<Coordinate, Tile> m_tiles;
};

#endif // ROOMOBJECT_H
