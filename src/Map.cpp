#include <iostream>

#include "Map.h"
#include "RoomObject.h"
#include "WorldObject.h"
#include "DrawableObject.h"

Map::Map()
{

}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for(WorldObject *object : m_objects)
	{
		DrawableObject *drawable = dynamic_cast<DrawableObject *>(object);

		if(drawable)
		{
			target.draw(*drawable, states);
		}
	}
}

void Map::update(const int delta)
{
	const std::list<WorldObject *> objects = m_objects;

	for(WorldObject *object : objects)
	{
		if(object)
		{
			const bool alive = object->update(delta);

			if(!alive)
			{
				delete object;
			}
		}
	}
}

void Map::addObject(WorldObject *worldObject)
{
	m_objects.push_back(worldObject);
	m_objects.sort(&DrawableObject::compare);
}

void Map::removeObject(WorldObject *worldObject)
{
	m_objects.remove(worldObject);
}
