#ifndef PLAYER_H
#define PLAYER_H

#include "Box2D/Dynamics/b2Body.h"

#include "DrawableObject.h"

class Player : public DrawableObject
{
	public:
		Player(WorldPosition *position);

		void onCollision(const WorldObject *other) override;
		void onSensorDetection(const b2Fixture *sensor, const WorldObject *other) override;

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		void update();

		b2Vec2 movement() const;
		void setMovement(const b2Vec2 &movement);

	private:
		b2Body *m_body;

		b2Vec2 m_movement;
};

#endif // PLAYER_H
