#include <iostream>

#include "IRoomPlacementStrategy.h"
#include "RoomPlacementStrategySelector.h"
#include "WorldGeneratorContext.h"
#include "Room.h"

WorldGeneratorContext::WorldGeneratorContext(std::set<int> &generatedRooms, RoomPlacementStrategySelector &selector)
	: m_generatedRooms(generatedRooms)
	, m_selector(selector)
	, m_direction(Direction::None)
	, m_x(0)
	, m_y(0)
{

}

WorldGeneratorContext::WorldGeneratorContext(const WorldGeneratorContext &other, const Direction::Value direction, const int x, const int y)
	: m_generatedRooms(other.m_generatedRooms)
	, m_selector(other.m_selector)
	, m_direction(direction)
	, m_x(x)
	, m_y(y)
{

}

WorldGeneratorContext WorldGeneratorContext::fork(const Room &current, const Room &next, const Direction::Value direction)
{
	const IRoomPlacementStrategy *strategy = m_selector.select(direction);
	const Coordinate offset = strategy->position(current, next);
	const WorldGeneratorContext forked(*this, direction, m_x + offset.first, m_y + offset.second);

	std::cout << m_x << "x" << m_y << std::endl;

	return forked;
}

Direction::Value WorldGeneratorContext::direction() const
{
	return m_direction;
}

Direction::Value WorldGeneratorContext::reverse() const
{
	return Direction::reverse(m_direction);
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
