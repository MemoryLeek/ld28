#include "CollidableObject.h"

CollidableObject::CollidableObject(int x, int y, const sf::Texture &texture, CollidableObject::CollidableObjectType type)
	: DrawableObject(x, y, texture)
	, m_type(type)
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
