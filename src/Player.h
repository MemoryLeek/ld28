#ifndef PLAYER_H
#define PLAYER_H

#include "Box2D/Dynamics/b2Body.h"

#include "DrawableObject.h"

class TreasureContainer;

class Player : public DrawableObject
{
	public:
		Player(WorldPosition *position);

		void onCollision(const WorldObject *other) override;
		void onSensorEnter(const b2Fixture *sensor, WorldObject *other) override;
		void onSensorLeave(const b2Fixture *sensor, WorldObject *other) override;

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		void update();

		void interact();

		b2Vec2 movement() const;
		void setMovement(const b2Vec2 &movement);

	private:
		b2Body *m_body;

		b2Vec2 m_movement;
		TreasureContainer *m_interactable;
};

#endif // PLAYER_H
