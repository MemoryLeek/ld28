#ifndef WORLDPOSITION_H
#define WORLDPOSITION_H

#include <Box2D/Common/b2Math.h>

class WorldPosition
{
	public:
		virtual ~WorldPosition()
		{

		}

		virtual b2Vec2 position() const = 0;
		virtual void setPosition(const b2Vec2 &position) = 0;

		virtual float rotation() const = 0;
		virtual void setRotation(float rotation) = 0;

		virtual b2Vec2 size() const = 0;
		virtual void setSize(const b2Vec2 &size) = 0;
};

#endif // WORLDPOSITION_H
