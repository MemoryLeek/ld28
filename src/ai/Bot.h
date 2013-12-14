#ifndef BOT_H
#define BOT_H

#include <list>
#include <stack>

#include <Box2D/Common/b2Math.h>
#include <Box2D/Dynamics/b2Fixture.h>

#include <SFML/System/Clock.hpp>

#include "DrawableObject.h"
#include "RayCastResult.h"

class Pathfinder;

class Bot : public DrawableObject
{
	public:
		Bot(WorldPosition *position, const std::list<const WorldObject *> &enemies, const Pathfinder *pathfinder);

		void onCollision(const WorldObject *other) override;
		void onSensorEnter(const b2Fixture *sensor, WorldObject *other) override;
		void onSensorLeave(const b2Fixture *sensor, WorldObject *other) override;

		virtual void onTargetSpotted(const WorldObject *target) = 0;
		virtual void onTargetHeard(const WorldObject *target) = 0;
		virtual void onPathEnd() = 0;

		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

		void update();

	protected:
		bool moveTo(const b2Vec2 &position);
		float distanceTo(const WorldObject *object) const;

	private:
		bool hasVisionTo(const WorldObject *object) const;

		b2Body *m_body;
		const std::list<const WorldObject *> m_enemies;
		const Pathfinder *m_pathfinder;
		const float m_maxVisionDistance;

		b2Fixture *m_hearingSensor;
		b2Fixture *m_visionSensor;

		std::stack<b2Vec2> m_path;
		std::list<WorldObject*> m_trackedTargets;
};

#endif // BOT_H
