#include "InteractableObject.h"

InteractableObject::InteractableObject(WorldPosition *position)
	: DrawableObject(position, 32, 32)
{
}

void InteractableObject::onCollision(const WorldObject *other)
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
