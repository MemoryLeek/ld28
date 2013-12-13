#include "RoomLookup.h"
#include "StreamingOperators.h"

RoomLookup::RoomLookup()
{

}

std::list<RoomObject> RoomLookup::rooms() const
{
	return m_rooms;
}

BinaryStream &operator >>(BinaryStream &stream, RoomLookup &lookup)
{
	stream >> lookup.m_rooms;

	return stream;
}
