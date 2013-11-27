#include "PhysicsWorldPosition.h"

PhysicsWorldPosition::PhysicsWorldPosition(b2Body *body)
	: m_body(body)
{
}


b2Vec2 PhysicsWorldPosition::position() const
{
	b2Vec2 position = m_body->GetPosition();
	position *= World::scale();
	return position;
}

void PhysicsWorldPosition::setPosition(const b2Vec2 &position)
{
	b2Vec2 newPosition(position.x / World::scale(),
					   position.y / World::scale());

	m_body->SetTransform(newPosition, m_body->GetAngle());
}

float PhysicsWorldPosition::rotation() const
{
	return m_body->GetAngle() * 180 / M_PI;
}

void PhysicsWorldPosition::setRotation(float rotation)
{
	m_body->SetTransform(m_body->GetPosition(), rotation * M_PI / 180);
}

b2Body *PhysicsWorldPosition::body() const
{
	return m_body;
}
