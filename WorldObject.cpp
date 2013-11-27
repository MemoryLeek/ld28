#include "WorldObject.h"

WorldObject::WorldObject(const WorldPosition *position, int width, int height)
	: m_worldPosition(position)
{
}

const WorldPosition *WorldObject::worldPosition() const
{
	return m_worldPosition;
}
