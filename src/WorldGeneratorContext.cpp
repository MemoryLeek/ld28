#include <iostream>

#include "IRoomPlacementStrategy.h"
#include "RoomPlacementStrategySelector.h"
#include "WorldGeneratorContext.h"
#include "CoordinateRect.h"
#include "Room.h"

WorldGeneratorContext::WorldGeneratorContext(std::set<int> &generatedRooms, std::set<Coordinate> &generatedTiles, RoomPlacementStrategySelector &selector)
	: m_generatedRooms(generatedRooms)
	, m_generatedTiles(generatedTiles)
	, m_selector(selector)
	, m_direction(Direction::None)
	, m_x(0)
	, m_y(0)
{

}

WorldGeneratorContext::WorldGeneratorContext(const WorldGeneratorContext &other, const Direction::Value direction, const int x, const int y)
	: m_generatedRooms(other.m_generatedRooms)
	, m_generatedTiles(other.m_generatedTiles)
	, m_selector(other.m_selector)
	, m_direction(direction)
	, m_x(x)
	, m_y(y)
{

}

WorldGeneratorContext WorldGeneratorContext::fork(const Room &first, const Room &second, const Direction::Value direction)
{
	const IRoomPlacementStrategy *strategy = m_selector.select(direction);
	const Coordinate offset = strategy->position(first, second);
	const WorldGeneratorContext forked(*this, direction, m_x + offset.first, m_y + offset.second);

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

bool WorldGeneratorContext::isTileGenerated(const Coordinate &tile) const
{
	const Coordinate coordinate(m_x + tile.first, m_y + tile.second);

	return m_generatedTiles.find(coordinate) != m_generatedTiles.end();
}

void WorldGeneratorContext::markAsGenerated(const Coordinate &tile)
{
	const Coordinate coordinate(m_x + tile.first, m_y + tile.second);

	m_generatedTiles.insert(coordinate);
}

bool WorldGeneratorContext::canFitRoom(const Room &first, const Room &second, const Direction::Value direction) const
{
	const int width = second.width();
	const int height = second.height();

	const IRoomPlacementStrategy *strategy = m_selector.select(direction);
	const Coordinate offset = strategy->position(first, second);

	const CoordinateRect rect(offset.first, offset.second, width, height);
	const Coordinate &topLeft = rect.topLeft();
	const Coordinate &topRight = rect.topRight();
	const Coordinate &bottomLeft = rect.bottomLeft();
	const Coordinate &bottomRight = rect.bottomRight();

	const bool canFitRoom =
		!isTileGenerated(topLeft) &&
		!isTileGenerated(topRight) &&
		!isTileGenerated(bottomLeft) &&
		!isTileGenerated(bottomRight);

	return canFitRoom;
}

int WorldGeneratorContext::x() const
{
	return m_x;
}

int WorldGeneratorContext::y() const
{
	return m_y;
}
