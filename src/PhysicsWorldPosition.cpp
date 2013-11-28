#include "PhysicsWorldPosition.h"

PhysicsWorldPosition::PhysicsWorldPosition(b2Body *body)
	: m_body(body)
{
}


b2Vec2 PhysicsWorldPosition::position() const
{
	b2Vec2 position = m_body->GetPosition();
	position *= World::SCALE;
	return position;
}

void PhysicsWorldPosition::setPosition(const b2Vec2 &position)
{
	b2Vec2 newPosition(position.x / World::SCALE,
					   position.y / World::SCALE);

	m_body->SetTransform(newPosition, m_body->GetAngle());
	m_body->SetAwake(true);
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
