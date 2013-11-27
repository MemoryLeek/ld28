#ifndef WORLD_H
#define WORLD_H

#include <Box2D/Dynamics/b2World.h>

#include "Map.h"

class PhysicsWorldPosition;

class World : public b2World
{
	public:
		World();

		PhysicsWorldPosition *createStaticBox(const b2Vec2 &position, int width, int height);

		static float scale();

	private:
		static float m_worldScale;
};

#endif // WORLD_H
