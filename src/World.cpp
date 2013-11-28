#include <chrono>
#include <thread>

#include <Box2D/Box2D.h>

#include "PhysicsWorldPosition.h"
#include "TileObject.h"
#include "World.h"

float World::m_worldScale = 32 / 0.5f; // Scale world as 32 px tiles and 1 tile is 0.5m

World::World() :
	b2World(b2Vec2(0, 0))
{
	SetAutoClearForces(false);
}

PhysicsWorldPosition *World::createBox(const b2Vec2 &position, int width, int height, b2BodyType type)
{
	float scaledWidth = width / m_worldScale;
	float scaledheight = height / m_worldScale;
	b2Vec2 scaledPosition(position.x / m_worldScale,
						  position.y / m_worldScale);

	b2BodyDef bodyDefinition;
	bodyDefinition.position = scaledPosition;
	bodyDefinition.type = type;

	b2Body *body = CreateBody(&bodyDefinition);

	b2PolygonShape shape;
	shape.SetAsBox(scaledWidth / 2, scaledheight / 2);
	body->CreateFixture(&shape, 1.0f);

	return new PhysicsWorldPosition(body);
}

float World::scale()
{
	return m_worldScale;
}
