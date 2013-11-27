#include "Map.h"
#include "DrawableObject.h"

Map::Map()
{

}

std::list<const WorldObject *> Map::objects() const
{
	return m_objects;
}

void Map::addObject(const WorldObject *object)
{
	m_objects.push_back(object);
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for(const WorldObject *object : m_objects)
	{
		const DrawableObject *drawable = dynamic_cast<const DrawableObject *>(object);

		if(drawable)
		{
			target.draw(*drawable, states);
		}
	}
}
