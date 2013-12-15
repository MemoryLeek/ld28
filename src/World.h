#ifndef WORLD_H
#define WORLD_H

#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <Box2D/Dynamics/b2World.h>

#include "RoomObject.h"

class PhysicsWorldPosition;
class Sensor;

class World : public b2World
{
	public:
		enum CollisionGroup
		{
			Player = 0x0002,
			PlayerProjectile = 0x0004
		};

		World();

		PhysicsWorldPosition *createCircle(const b2Vec2 &position, int radius, b2BodyType type = b2_staticBody, const b2Filter &filter = b2Filter());
		PhysicsWorldPosition *createBox(const b2Vec2 &position, int width, int height, b2BodyType type = b2_staticBody, const b2Filter &filter = b2Filter());

		static const float SCALE;
};

#endif // WORLD_H
