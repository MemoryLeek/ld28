#include "InteractableObject.h"

InteractableObject::InteractableObject(const sf::String &fileName, WorldPosition *position)
	: AnimatedObject(fileName, position)
{
}

InteractableObject::~InteractableObject()
{

}

void InteractableObject::onCollision(WorldObject *other)
{
}

void InteractableObject::onSensorEnter(const b2Fixture *sensor, WorldObject *other)
{
}

void InteractableObject::onSensorLeave(const b2Fixture *sensor, WorldObject *other)
{
}

int InteractableObject::drawingOrder() const
{
	return 1;
}
