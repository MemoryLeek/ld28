#include "StaticWorldPosition.h"

StaticWorldPosition::StaticWorldPosition(const b2Vec2 &position, const b2Vec2 &size)
	: m_position(position)
	, m_size(size)
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

b2Vec2 StaticWorldPosition::size() const
{
	return m_size;
}

void StaticWorldPosition::setSize(const b2Vec2 &size)
{
	m_size = size;
}
