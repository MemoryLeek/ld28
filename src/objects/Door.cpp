#include <iostream>

#include "Door.h"
#include "Room.h"
#include "PhysicsWorldPosition.h"

Door::Door(WorldPosition *worldPosition, const Direction::Value direction, const sf::String &fileName)
	: InteractableObject(fileName, worldPosition)
{

}

void Door::onCollision(WorldObject *other)
{

}

void Door::onSensorEnter(const b2Fixture *sensor, WorldObject *other)
{

}

void Door::onSensorLeave(const b2Fixture *sensor, WorldObject *other)
{

}

void Door::onInteraction()
{
	WorldPosition &position = worldPosition();
	PhysicsWorldPosition *physicsPosition = dynamic_cast<PhysicsWorldPosition *>(&position);

	if(physicsPosition)
	{
		physicsPosition->suspendCollision();
	}

	setImageIndex(1);
}
