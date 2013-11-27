#include "StaticWorldPosition.h"

StaticWorldPosition::StaticWorldPosition(const b2Vec2 &position)
	: m_position(position)
	, m_rotation(0)
{
}

b2Vec2 StaticWorldPosition::position() const
{
	return m_position;
}

void StaticWorldPosition::setPosition(const b2Vec2 &position)
{
	m_position = position;
}

float StaticWorldPosition::rotation() const
{
	return m_rotation;
}

void StaticWorldPosition::setRotation(float rotation)
{
	m_rotation = rotation;
}
