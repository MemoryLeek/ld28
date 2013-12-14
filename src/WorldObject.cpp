#include "PhysicsWorldPosition.h"

#include "WorldObject.h"

WorldObject::WorldObject(WorldPosition *position, int width, int height)
	: m_width(width)
	, m_height(height)
	, m_worldPosition(position)
{
	PhysicsWorldPosition *physicsPosition = dynamic_cast<PhysicsWorldPosition*>(position);
	if(physicsPosition)
	{
		physicsPosition->body()->SetUserData(this);
	}
}

int WorldObject::width() const
{
	return m_width;
}

int WorldObject::height() const
{
	return m_height;
}

WorldPosition &WorldObject::worldPosition() const
{
	return *m_worldPosition;
}
