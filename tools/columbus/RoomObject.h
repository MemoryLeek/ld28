#ifndef ROOMOBJECT_H
#define ROOMOBJECT_H

#include <QHash>

#include "TileObject.h"
#include "Direction.h"
#include "MapType.h"

using Coordinate = QPair<unsigned int, unsigned int>;

class Room
{
	friend QDataStream &operator <<(QDataStream &stream, const Room &room);

	public:
		Room(MapType::Value type, const int width, const int height);

		void addTile(Coordinate coordinate, const TileObject &tile);
		void setEntrance(const Direction::Value direction, const Coordinate coordinate);

	private:
		MapType::Value m_type;

		QHash<Coordinate, TileObject> m_tiles;
		QHash<Direction::Value, Coordinate> m_entrances;

		int m_width;
		int m_height;
};

#endif // ROOMOBJECT_H
