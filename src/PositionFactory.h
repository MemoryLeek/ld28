#ifndef POSITIONFACTORY_H
#define POSITIONFACTORY_H

#include <Box2D/Common/b2Math.h>

class World;
class WorldPosition;

class PositionFactory
{
	public:
		PositionFactory(World *world);

		WorldPosition *create(bool isCollidable, b2Vec2 position, int width, int height) const;

	private:
		World *m_world;
};

#endif // POSITIONFACTORY_H
