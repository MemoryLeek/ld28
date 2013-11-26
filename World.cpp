#include <Box2D/Box2D.h>

#include "TileObject.h"
#include "World.h"

float World::m_worldScale = 32 / 0.5f; // Scale world as 32 px tiles and 1 tile is 0.5m

World::World() :
	b2World(b2Vec2(0, 0))
{
}

void World::addCollidable(CollidableObject *collidable)
{
	float x = collidable->left / m_worldScale;
	float y = collidable->top / m_worldScale;
	float width = collidable->width / m_worldScale;
	float height = collidable->height / m_worldScale;

	// Define the body
	b2BodyDef bodyDefinition;
	bodyDefinition.userData = collidable;
	bodyDefinition.position.Set(x, y);
	if(collidable->type() == CollidableObject::DynamicCollidable)
		bodyDefinition.type = b2_dynamicBody;

	// Create it and attach it to the collidable
	b2Body *body = CreateBody(&bodyDefinition);
	collidable->setBody(body);

	// Create the collidable shape and fixture
	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height / 2); // NOTE: Takes half-width and half-height
	body->CreateFixture(&shape, 1.0f);
}

void World::addWalls(const Map &map)
{
	for(const WorldObject *object : map.objects())
	{
		const TileObject *tile = dynamic_cast<const TileObject *>(object);

		if(tile && tile->isCollidable())
		{
			float width = tile->width / m_worldScale;
			float height = tile->height / m_worldScale;
			float x = tile->left / m_worldScale + width / 2;
			float y = tile->top / m_worldScale + height / 2;

			b2BodyDef bodyDefinition;
			bodyDefinition.position.Set(x, y);

			b2Body *body = CreateBody(&bodyDefinition);

			b2PolygonShape shape;
			shape.SetAsBox(width / 2, height / 2);
			body->CreateFixture(&shape, 1.0f);
		}
	}
}

float World::scale()
{
	return m_worldScale;
}
