#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "PhysicsWorldPosition.h"
#include "Player.h"

Player::Player(WorldPosition *position)
	: DrawableObject(position, 32, 32)
{
	const PhysicsWorldPosition *physicsWorldPosition = static_cast<PhysicsWorldPosition*>(worldPosition());
	m_body = physicsWorldPosition->body();
	m_body->SetFixedRotation(true);
}


void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
}

void Player::setMovement(const b2Vec2 &velocity)
{
	const b2Vec2 &targetVelocity = m_body->GetWorldVector(velocity);
	const b2Vec2 &currentVelocity = m_body->GetLinearVelocity();
	const float mass = m_body->GetMass();

	float xImpulse = mass * (targetVelocity.x - currentVelocity.x);
	float yImpulse = mass * (targetVelocity.y - currentVelocity.y);
	m_body->ApplyLinearImpulse(b2Vec2(xImpulse, yImpulse), m_body->GetWorldCenter(), true);
}
