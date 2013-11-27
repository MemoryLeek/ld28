#ifndef PLAYER_H
#define PLAYER_H

#include "DrawableObject.h"

class Player : public DrawableObject
{
	public:
		Player(WorldPosition *position);

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		void setLinearVelocity(const b2Vec2 &velocity);
};

#endif // PLAYER_H
