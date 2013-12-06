#ifndef BOT_H
#define BOT_H

#include <list>

#include <Box2D/Common/b2Math.h>

#include <SFML/System/Clock.hpp>

#include "DrawableObject.h"
#include "RayCastResult.h"

class Bot : public DrawableObject
{
	public:
		Bot(WorldPosition *position, const std::list<const WorldObject *> enemies);

		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

		void update();

	private:
		const WorldObject *findTarget();

		float distanceTo(const WorldObject *object) const;

		static const float RAYCAST_INTERVAL;

		const std::list<const WorldObject *> m_enemies;
		const float m_maxVisionDistance;
		b2Body *m_body;

		RayCastResult m_rayCast;
		sf::Clock m_rayCastTimer;

		const WorldObject *m_target;

		b2Vec2 m_destination;
};

#endif // BOT_H
