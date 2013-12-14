#include "TreasureContainer.h"

TreasureContainer::TreasureContainer(WorldPosition *position)
	: DrawableObject(position, 32, 32)
{
}

void TreasureContainer::onCollision(const WorldObject *other)
{
}

void TreasureContainer::onSensorEnter(const b2Fixture *sensor, WorldObject *other)
{
}

void TreasureContainer::onSensorLeave(const b2Fixture *sensor, WorldObject *other)
{
}

void TreasureContainer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
}
