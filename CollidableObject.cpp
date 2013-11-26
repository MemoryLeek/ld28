#include "CollidableObject.h"

CollidableObject::CollidableObject(int x, int y, int width, int height)
	: DrawableObject(x, y, width, height)
	, m_type(StaticCollidable)
	, m_body(NULL)
{

}

CollidableObject::CollidableObjectType CollidableObject::type() const
{
	return m_type;
}

void CollidableObject::setBody(b2Body *body)
{
	m_body = body;
}
