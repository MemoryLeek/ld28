#include "WorldObject.h"
#include "PhysicsWorldPosition.h"
#include "Map.h"

WorldObject::WorldObject(WorldPosition *position)
	: m_worldPosition(position)
{
	PhysicsWorldPosition *physicsPosition = dynamic_cast<PhysicsWorldPosition*>(position);
	if(physicsPosition)
	{
		physicsPosition->body()->SetUserData(this);
	}
}

WorldObject::~WorldObject()
{
	delete m_worldPosition;
}

WorldPosition &WorldObject::worldPosition() const
{
	return *m_worldPosition;
}
