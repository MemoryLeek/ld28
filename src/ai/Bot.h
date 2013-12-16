#ifndef BOT_H
#define BOT_H

#include <list>
#include <stack>

#include <Box2D/Common/b2Math.h>
#include <Box2D/Dynamics/b2Fixture.h>

#include <SFML/System/Clock.hpp>

#include "Damagable.h"
#include "AnimatedObject.h"
#include "RayCastResult.h"
#include "Map.h"

class Pathfinder;
class Weapon;

class Bot : public AnimatedObject, public Damagable
{
	public:
		Bot(int health, WorldPosition *position, const std::list<const WorldObject *> &enemies, const Pathfinder *pathfinder, Map &map);
		virtual ~Bot();

		void onCollision(WorldObject *other) override;
		void onSensorEnter(const b2Fixture *sensor, WorldObject *other) override;
		void onSensorLeave(const b2Fixture *sensor, WorldObject *other) override;

		virtual void onUpdate(int delta) = 0;
		virtual void onTargetSpotted(const WorldObject *target) = 0;
		virtual void onTargetNoLongerVisible(const WorldObject *target) = 0;
		virtual void onTargetHeard(const WorldObject *target) = 0;
		virtual void onPathEnd() = 0;

		void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		int drawingOrder() const override;

		bool update(int delta) override;

		Weapon *weapon() const;
		void setWeapon(Weapon *weapon);

	protected:
		bool isMoving() const;

		void moveTo(const b2Vec2 &position);
		bool pathfind(const b2Vec2 &from, const b2Vec2 &to);
		bool pathfindTo(const b2Vec2 &position);
		float distanceTo(const WorldObject *object) const;
		bool hasVisionTo(const WorldObject *object) const;

	private:
		b2Body *m_body;
		const std::list<const WorldObject *> m_enemies;
		const Pathfinder *m_pathfinder;
		Map &m_map;
		const float m_maxVisionDistance;
		Weapon *m_weapon;

		b2Fixture *m_hearingSensor;
		b2Fixture *m_visionSensor;

		std::stack<b2Vec2> m_path;
		std::list<WorldObject*> m_visibleTargets;
};

#endif // BOT_H
