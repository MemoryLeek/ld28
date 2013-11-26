#ifndef WORLD_H
#define WORLD_H

#include <Box2D/Dynamics/b2World.h>

#include "CollidableObject.h"
#include "Map.h"

class World : public b2World
{
	public:
		World();

		void addCollidable(CollidableObject *collidable);

		void addWalls(const Map &map);

		static float scale();

	private:
		static float m_worldScale;
};

#endif // WORLD_H
