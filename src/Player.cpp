#include <iostream>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "PhysicsWorldPosition.h"
#include "Player.h"
#include "InteractableObject.h"

Player::Player(WorldPosition *position)
	: AnimatedObject("resources/test.spb", position, 32, 32)
	, m_movement(0, 0)
	, m_interactable(nullptr)
{
	const PhysicsWorldPosition &physicsWorldPosition = (PhysicsWorldPosition &)worldPosition();

	m_body = physicsWorldPosition.body();
	m_body->SetFixedRotation(true);

	setImageIndex(1);
}

void Player::onCollision(const WorldObject *other)
{

}

void Player::onSensorEnter(const b2Fixture *sensor, WorldObject *other)
{
	InteractableObject *treasure = dynamic_cast<InteractableObject*>(other);

	if(treasure)
	{
		m_interactable = treasure;
	}
}

void Player::onSensorLeave(const b2Fixture *sensor, WorldObject *other)
{
	InteractableObject *treasure = dynamic_cast<InteractableObject*>(other);
	if(treasure)
	{
		m_interactable = nullptr;
	}
}

void Player::update(const int delta)
{
	const b2Vec2 &currentVelocity = m_body->GetLocalVector(m_body->GetLinearVelocity());

	b2Vec2 impulse(0, 0);

	// Forward/back
	if(m_movement.x == 0)
	{
		impulse.x = (currentVelocity.x < 0) ? SPEED : -SPEED;
	}
	else
	{
		if(m_movement.x > 0 && currentVelocity.x < SPEED)
		{
			impulse.x = SPEED * 2;
		}
		if(m_movement.x < 0 && currentVelocity.x > -SPEED)
		{
			impulse.x = -SPEED * 2;
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

	AnimatedObject::update(delta);
}

void Player::interact()
{
	if(m_interactable)
	{
		m_interactable->onInteraction();
	}
}

b2Vec2 Player::movement() const
{
	return m_movement;
}

void Player::setMovement(const b2Vec2 &movement)
{
	m_movement = movement;
}
