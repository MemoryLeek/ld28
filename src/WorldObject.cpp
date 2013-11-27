#include "WorldObject.h"

WorldObject::WorldObject(WorldPosition *position, int width, int height)
	: m_worldPosition(position)
{
}

WorldPosition *WorldObject::worldPosition() const
{
	return m_worldPosition;
}
