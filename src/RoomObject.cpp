#include "RoomObject.h"
#include "DrawableObject.h"

std::list<const WorldObject *> RoomObject::objects() const
{
	return m_objects;
}

void RoomObject::addObject(const WorldObject *object)
{
	m_objects.push_back(object);
}

void RoomObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
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
