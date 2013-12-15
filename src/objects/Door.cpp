#include "Door.h"
#include "Room.h"

Door::Door(WorldPosition *worldPosition)
	: AnimatedObject("fileName", worldPosition)
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
