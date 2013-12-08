#include <chrono>
#include <thread>

#include <Box2D/Box2D.h>

#include "PhysicsWorldPosition.h"
#include "TileObject.h"
#include "World.h"

const float World::SCALE = 32 / 0.5f; // Scale world as 32 px tiles and 1 tile is 0.5m

World::World()
	: b2World(b2Vec2(0, 0))
{
	SetAutoClearForces(false);
}

PhysicsWorldPosition *World::createCircle(const b2Vec2 &position, int radius, b2BodyType type)
{
	float scaledRadius = radius / SCALE;
	b2Vec2 scaledPosition(position.x / SCALE,
						  position.y / SCALE);

	b2BodyDef bodyDefinition;
	bodyDefinition.position = scaledPosition;
	bodyDefinition.type = type;
	bodyDefinition.linearDamping = 1;

	b2Body *body = CreateBody(&bodyDefinition);

	b2CircleShape shape;
	shape.m_radius = scaledRadius;
	body->CreateFixture(&shape, 1.0f);

	return new PhysicsWorldPosition(body);
}

PhysicsWorldPosition *World::createBox(const b2Vec2 &position, int width, int height, b2BodyType type)
{
	float scaledWidth = width / SCALE;
	float scaledheight = height / SCALE;
	b2Vec2 scaledPosition(position.x / SCALE,
						  position.y / SCALE);

	b2BodyDef bodyDefinition;
	bodyDefinition.position = scaledPosition;
	bodyDefinition.type = type;
	bodyDefinition.linearDamping = 1;

	b2Body *body = CreateBody(&bodyDefinition);

	b2PolygonShape shape;
	shape.SetAsBox(scaledWidth / 2, scaledheight / 2);
	body->CreateFixture(&shape, 1.0f);

	return new PhysicsWorldPosition(body);
}
