#include "WorldObject.h"

WorldObject::WorldObject(WorldPosition *position, int width, int height)
	: m_worldPosition(position)
	, m_width(width)
	, m_height(height)
{
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
