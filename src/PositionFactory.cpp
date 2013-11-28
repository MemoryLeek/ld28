#include "PositionFactory.h"
#include "WorldPosition.h"
#include "StaticWorldPosition.h"
#include "PhysicsWorldPosition.h"
#include "World.h"

PositionFactory::PositionFactory(World *world)
	: m_world(world)
{

}

WorldPosition *PositionFactory::create(bool isCollidable, b2Vec2 position, int width, int height) const
{
	if(isCollidable)
	{
		return m_world->createBox(position, width, height);
	}
	else
	{
		return new StaticWorldPosition(position);
	}
}
