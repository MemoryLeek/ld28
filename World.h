#ifndef WORLD_H
#define WORLD_H

#include <Box2D/Dynamics/b2World.h>

#include "CollidableObject.h"

class World : public b2World
{
	public:
		World();

		void addCollidable(CollidableObject *collidable);

	private:
		const float m_worldScale;
};

#endif // WORLD_H
