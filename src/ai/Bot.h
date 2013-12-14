#ifndef BOT_H
#define BOT_H

#include <list>
#include <stack>

#include <Box2D/Common/b2Math.h>

#include <SFML/System/Clock.hpp>

#include "DrawableObject.h"
#include "RayCastResult.h"

class Pathfinder;

class Bot : public DrawableObject
{
	public:
		Bot(WorldPosition *position, const std::list<const WorldObject *> &enemies, const Pathfinder *pathfinder);

		virtual void onTargetSpotted() = 0;
		virtual void onPathEnd() = 0;

		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

		void update();

	protected:
		const WorldObject *closestVisibleTarget() const;

		bool moveTo(const b2Vec2 &position);
		float distanceTo(const WorldObject *object) const;

	private:
		void findTargets();

		static const float RAYCAST_INTERVAL;

		b2Body *m_body;
		const std::list<const WorldObject *> m_enemies;

		const Pathfinder *m_pathfinder;

		RayCastResult m_rayCast;
		sf::Clock m_rayCastTimer;
		const float m_maxVisionDistance;

		std::list<const WorldObject *> m_visibleTargets;

		std::stack<b2Vec2> m_path;
};

#endif // BOT_H
