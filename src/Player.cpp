#include <iostream>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "Player.h"
#include "PhysicsWorldPosition.h"
#include "InteractableObject.h"

#include "ui/FloatingPanel.h"

Player::Player(WorldPosition *position, FloatingPanel *interactionPanel)
	: AnimatedObject("resources/test.spb", position)
	, m_movement(0, 0)
	, m_interactable(nullptr)
	, m_interactionPanel(interactionPanel)
	, m_weapon(nullptr)
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
	InteractableObject *interactable = dynamic_cast<InteractableObject*>(other);

	if(interactable)
	{
		m_interactable = interactable;
		m_interactionPanel->setVisible(true);
	}
}

void Player::onSensorLeave(const b2Fixture *sensor, WorldObject *other)
{
	InteractableObject *interactable = dynamic_cast<InteractableObject*>(other);

	if(interactable)
	{
		m_interactable = nullptr;
		m_interactionPanel->setVisible(false);
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

Weapon *Player::weapon() const
{
	sf::SoundBuffer *b = new sf::SoundBuffer();
	b->loadFromFile("resources/stup.wav");

	sf::Sound *sound = new sf::Sound();
	sound->setBuffer(*b);
	sound->play();

	std::cout << "aiuysd" << std::endl;

	// Disable weapon on interactables
	if(m_interactable)
	{
		return nullptr;
	}

	return m_weapon;
}

void Player::setWeapon(Weapon *weapon)
{
	m_weapon = weapon;
}
