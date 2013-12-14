#include <iostream>

#include "IdGenerator.h"
#include "Room.h"
#include "StaticWorldPosition.h"
#include "StreamingOperators.h"

Room::Room()
{
	m_id = IdGenerator::next();
}

MapType::Value Room::type() const
{
	return m_type;
}

std::map<Coordinate, Tile> Room::tiles() const
{
	return m_tiles;
}

std::map<Direction::Value, Coordinate> Room::entrances() const
{
	return m_entrances;
}

std::vector<Direction::Value> Room::directions() const
{
	std::map<Direction::Value, Coordinate>::const_iterator iterator = m_entrances.begin();
	std::vector<Direction::Value> directions;

	for(; iterator != m_entrances.end(); iterator++)
	{
		directions.push_back(iterator->first);
	}

	return directions;
}

Coordinate Room::entrance(const Direction::Value direction) const
{
	return m_entrances.at(direction);
}

int Room::weight() const
{
	return m_tiles.size();
}

int Room::id() const
{
	return m_id;
}

int Room::width() const
{
	return m_width;
}

int Room::height() const
{
	return m_height;
}

bool Room::isStart(const Room &room)
{
	return room.type() == MapType::Start;
}

bool Room::isEnd(const Room &room)
{
	return room.type() == MapType::End;
}

BinaryStream &operator >>(BinaryStream &stream, Room &room)
{
	stream >> room.m_type;
	stream >> room.m_width;
	stream >> room.m_height;
	stream >> room.m_tiles;
	stream >> room.m_entrances;

	return stream;
}
