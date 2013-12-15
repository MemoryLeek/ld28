#include <iostream>

#include "RoomObject.h"
#include "DrawableObject.h"

RoomObject::RoomObject()
	: DrawableObject(0)
{

}

void RoomObject::addObject(WorldObject *object)
{
	m_objects.push_back(object);
}

void RoomObject::done()
{
	m_objects.sort(&DrawableObject::compare);
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

void RoomObject::onCollision(WorldObject *other)
{

}

void RoomObject::onSensorEnter(const b2Fixture *sensor, WorldObject *other)
{

}

void RoomObject::onSensorLeave(const b2Fixture *sensor, WorldObject *other)
{

}

bool RoomObject::update(const int delta)
{
	for(WorldObject *object : m_objects)
	{
		object->update(delta);
	}

	return true;
}
