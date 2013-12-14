#ifndef WORLD_H
#define WORLD_H

#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2World.h>

#include "RoomObject.h"

class PhysicsWorldPosition;

class World : public b2World
{
	public:
		World();

		PhysicsWorldPosition *createCircle(const b2Vec2 &position, int radius, b2BodyType type = b2_staticBody);
		PhysicsWorldPosition *createBox(const b2Vec2 &position, int width, int height, b2BodyType type = b2_staticBody);

		static const float SCALE;
};

#endif // WORLD_H
