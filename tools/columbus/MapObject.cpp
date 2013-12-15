#include "MapObject.h"

MapObject::MapObject()
	: m_id(-1)
	, m_direction(0)
{

}

MapObject::MapObject(const int id, const int direction)
	: m_id(id)
	, m_direction(direction)
{

}

QDataStream &operator <<(QDataStream &stream, const MapObject &object)
{
	stream << object.m_id;
	stream << object.m_direction;

	return stream;
}
