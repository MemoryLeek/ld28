#include <iostream>

#include "WorldGeneratorContext.h"
#include "Room.h"

WorldGeneratorContext::WorldGeneratorContext(std::set<int> &generatedRooms)
	: m_generatedRooms(generatedRooms)
	, m_x(0)
	, m_y(0)
{

}

WorldGeneratorContext::WorldGeneratorContext(std::set<int> &generatedRooms, const int x, const int y)
	: m_generatedRooms(generatedRooms)
	, m_x(x)
	, m_y(y)
{

}

WorldGeneratorContext WorldGeneratorContext::fork(const Room &current, const Room &next)
{
	const int width = current.width();
	const int height = current.height();

	std::cout << width << "x" << height << std::endl;

	return WorldGeneratorContext(m_generatedRooms, m_x + width, m_y + height);
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
