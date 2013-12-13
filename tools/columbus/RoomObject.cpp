#include "RoomObject.h"
#include "TileObject.h"

RoomObject::RoomObject()
{

}

void RoomObject::addTile(Coordinate coordinate, const Tile &tile)
{
	m_tiles[coordinate] = tile;
}

QDataStream &operator <<(QDataStream &stream, const RoomObject &room)
{
	stream << room.m_tiles;

	return stream;
}
