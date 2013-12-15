#include "MapObject.h"

MapObject::MapObject()
	: m_id(-1)
	, m_direction(0)
{

}

int MapObject::id() const
{
	return m_id;
}

int MapObject::direction() const
{
	return m_direction;
}

BinaryStream &operator >>(BinaryStream &stream, MapObject &object)
{
	stream >> object.m_id;
	stream >> object.m_direction;

	return stream;
}
