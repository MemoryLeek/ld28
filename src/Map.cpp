#include "Map.h"
#include "RoomObject.h"

Map::Map()
{

}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for(RoomObject *room : m_rooms)
	{
		room->draw(target, states);
	}
}

void Map::addRoom(RoomObject *room)
{
	m_rooms.push_back(room);
}
