#include "RoomLookup.h"
#include "StreamingOperators.h"

RoomLookup::RoomLookup()
{

}

std::vector<Room> &RoomLookup::rooms()
{
	return m_rooms;
}

BinaryStream &operator >>(BinaryStream &stream, RoomLookup &lookup)
{
	stream >> lookup.m_rooms;

	return stream;
}
