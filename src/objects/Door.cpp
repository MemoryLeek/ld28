#include "Door.h"
#include "Room.h"

Door::Door(WorldPosition *worldPosition)
	: AnimatedObject("fileName", worldPosition, TILE_SIZE, TILE_SIZE)
{

}

void Door::onCollision(const WorldObject *other)
{

}

void Door::onSensorEnter(const b2Fixture *sensor, WorldObject *other)
{

}

void Door::onSensorLeave(const b2Fixture *sensor, WorldObject *other)
{

}
