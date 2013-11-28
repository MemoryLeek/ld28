#ifndef PLAYER_H
#define PLAYER_H

#include "Box2D/Dynamics/b2Body.h"

#include "DrawableObject.h"

class Player : public DrawableObject
{
	public:
		Player(WorldPosition *position);

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		void setMovement(const b2Vec2 &velocity);

	private:
		b2Body *m_body;
};

#endif // PLAYER_H
