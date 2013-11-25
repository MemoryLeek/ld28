#ifndef COLLIDABLEOBJECT_H
#define COLLIDABLEOBJECT_H

#include <Box2D/Dynamics/b2Body.h>

#include "MapObject.h"
#include "DrawableObject.h"

class CollidableObject : public DrawableObject
{
	public:
		enum CollidableObjectType
		{
			StaticCollidable,
			DynamicCollidable
		};

		CollidableObject(const sf::Texture &texture, CollidableObject::CollidableObjectType type);

		CollidableObjectType type() const;

	private:
		void setBody(b2Body *body);

		CollidableObjectType m_type;
		b2Body *m_body;

		friend class World;
};

#endif // COLLIDABLEOBJECT_H
