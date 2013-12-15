#include "InteractableObject.h"

InteractableObject::InteractableObject(WorldPosition *position)
	: DrawableObject(position)
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

void InteractableObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
}
