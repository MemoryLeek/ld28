#include <iostream>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "PhysicsWorldPosition.h"
#include "Player.h"

Player::Player(WorldPosition *position)
	: DrawableObject(position, 32, 32)
	, m_movement(0, 0)
{
	const PhysicsWorldPosition &physicsWorldPosition = (PhysicsWorldPosition &)worldPosition();

	m_body = physicsWorldPosition.body();
	m_body->SetFixedRotation(true);
}

void Player::onCollision(const WorldObject *other)
{
	std::cout << "Player collided with another object." << std::endl;
}

void Player::onSensorDetection(const b2Fixture *sensor, const WorldObject *other)
{
	std::cout << "Player sensor triggered." << std::endl;
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
}

void Player::update()
{
	const b2Vec2 &currentVelocity = m_body->GetLocalVector(m_body->GetLinearVelocity());

	const int speed = 5;

	b2Vec2 impulse(0, 0);

	// Forward/back
	if(m_movement.x == 0)
	{
		impulse.x = (currentVelocity.x < 0) ? speed : -speed;
	}
	else
	{
		if(m_movement.x > 0 && currentVelocity.x < speed)
		{
			impulse.x = speed * 2;
		}
		if(m_movement.x < 0 && currentVelocity.x > -speed)
		{
			impulse.x = -speed * 2;
		}
	}

	// Left/right
	if(m_movement.y == 0)
	{
		impulse.y = (currentVelocity.y < 0) ? 2 : -2;
	}
	else
	{
		if(m_movement.y > 0 && currentVelocity.y < 1)
		{
			impulse.y = 4;
		}
		if(m_movement.y < 0 && currentVelocity.y > -1)
		{
			impulse.y = -4;
		}
	}

	m_body->ApplyForce(m_body->GetWorldVector(impulse), m_body->GetWorldCenter(), true);
}

b2Vec2 Player::movement() const
{
	return m_movement;
}

void Player::setMovement(const b2Vec2 &movement)
{
	m_movement = movement;
}
