#include <QDebug>

#include "RoomObject.h"
#include "TileObject.h"

Room::Room(MapType::Value type, const int width, const int height)
	: m_type(type)
	, m_width(width)
	, m_height(height)
{

}

void Room::addTile(Coordinate coordinate, const TileObject &tile)
{
	m_tiles[coordinate] = tile;
}

void Room::setEntrance(const Direction::Value direction, const Coordinate coordinate)
{
	m_entrances[direction] = coordinate;
}

QDataStream &operator <<(QDataStream &stream, const Room &room)
{
	stream << room.m_type;
	stream << room.m_width;
	stream << room.m_height;
	stream << room.m_tiles;
	stream << room.m_entrances;

	qDebug() << room.m_entrances.count();

	return stream;
}
