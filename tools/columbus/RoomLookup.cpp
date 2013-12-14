#include <QDebug>

#include "RoomLookup.h"
#include "RoomObject.h"

RoomLookup::RoomLookup()
{

}

void RoomLookup::addRoom(const Room &room)
{
	m_rooms << room;
}

QDataStream &operator <<(QDataStream &stream, const RoomLookup &lookup)
{
	stream << lookup.m_rooms;

	return stream;
}
