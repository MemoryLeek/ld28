#ifndef WORLDPOSITION_H
#define WORLDPOSITION_H

#include <Box2D/Common/b2Math.h>

class WorldPosition
{
	public:
		virtual b2Vec2 position() const = 0;
		virtual void setPosition(const b2Vec2 &position) = 0;

		virtual float rotation() const = 0;
		virtual void setRotation(float rotation) = 0;
};

#endif // WORLDPOSITION_H
