#ifndef PLAYER_H
#define PLAYER_H

#include <Box2D/Dynamics/b2Body.h>

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include "AnimatedObject.h"
#include "Damagable.h"

class InteractableObject;
class FloatingPanel;
class Weapon;

const int SPEED = 2;

class Player : public AnimatedObject, public Damagable
{
	public:
		Player(WorldPosition *position, FloatingPanel *interactionPanel, const sf::SoundBuffer &stepSound);

		void onCollision(WorldObject *other) override;
		void onSensorEnter(const b2Fixture *sensor, WorldObject *other) override;
		void onSensorLeave(const b2Fixture *sensor, WorldObject *other) override;

		bool update(const int delta);

		void interact();

		b2Vec2 movement() const;
		void setMovement(const b2Vec2 &movement);

		Weapon *weapon() const;
		void setWeapon(Weapon *weapon);

	private:
		b2Body *m_body;
		b2Vec2 m_movement;

		InteractableObject *m_interactable;
		FloatingPanel *m_interactionPanel;
		Weapon *m_weapon;
		sf::Sound m_stepSound;
		int m_stepTimer;
};

#endif // PLAYER_H
