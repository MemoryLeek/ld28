#ifndef WORLD_H
#define WORLD_H

#include <mutex>

#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2World.h>

#include "Map.h"

class PhysicsWorldPosition;

class World : public b2World
{
	public:
		World();

		void physicsLoop();
		std::mutex &mutex();

		PhysicsWorldPosition *createBox(const b2Vec2 &position, int width, int height, b2BodyType type = b2_staticBody);

		static float scale();

	private:
		static float m_worldScale;

		std::mutex m_mutex;
};

#endif // WORLD_H
