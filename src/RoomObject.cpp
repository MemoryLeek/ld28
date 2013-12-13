#include <iostream>

#include "RoomObject.h"
#include "StaticWorldPosition.h"
#include "StreamingOperators.h"

RoomObject::RoomObject()
{

}

std::map<Coordinate, Tile> RoomObject::tiles() const
{
	return m_tiles;
}

BinaryStream &operator >>(BinaryStream &stream, RoomObject &room)
{
	stream >> room.m_tiles;

	return stream;
}
