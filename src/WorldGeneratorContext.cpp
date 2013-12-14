#include <iostream>

#include "WorldGeneratorContext.h"
#include "Room.h"

WorldGeneratorContext::WorldGeneratorContext(std::set<int> &generatedRooms)
	: m_generatedRooms(generatedRooms)
	, m_direction(Direction::None)
	, m_x(0)
	, m_y(0)
{

}

WorldGeneratorContext::WorldGeneratorContext(std::set<int> &generatedRooms, const Direction::Value direction, const int x, const int y)
	: m_generatedRooms(generatedRooms)
	, m_direction(direction)
	, m_x(x)
	, m_y(y)
{

}

WorldGeneratorContext WorldGeneratorContext::fork(const Room &current, const Room &next, const Direction::Value direction)
{
	const int width = current.width();
	const int height = current.height();

	const Direction::Value reverse = Direction::reverse(direction);
	const Coordinate c1 = current.entrance(direction);
	const Coordinate c2 = next.entrance(reverse);

	const int f = c1.second - c2.second;

	return WorldGeneratorContext(m_generatedRooms, direction, m_x + c1.first, m_y + f);
}

Direction::Value WorldGeneratorContext::direction() const
{
	return m_direction;
}

bool WorldGeneratorContext::isRoomGenerated(const Room &room) const
{
	const int id = room.id();

	return m_generatedRooms.find(id) != m_generatedRooms.end();
}

void WorldGeneratorContext::markAsGenerated(const Room &room)
{
	const int id = room.id();

	m_generatedRooms.insert(id);
}

int WorldGeneratorContext::x() const
{
	return m_x;
}

int WorldGeneratorContext::y() const
{
	return m_y;
}
