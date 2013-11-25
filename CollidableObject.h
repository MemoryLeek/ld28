#ifndef COLLIDABLEOBJECT_H
#define COLLIDABLEOBJECT_H

#include <Box2D/Dynamics/b2Body.h>

#include "MapObject.h"

class CollidableObject : public MapObject
{
	public:
		enum CollidableObjectType
		{
			StaticCollidable,
			DynamicCollidable
		};

		CollidableObject(CollidableObjectType type);

		CollidableObjectType type() const;

	private:
		void setBody(b2Body *body);

		CollidableObjectType m_type;
		b2Body *m_body;

	friend class World;
};

#endif // COLLIDABLEOBJECT_H
