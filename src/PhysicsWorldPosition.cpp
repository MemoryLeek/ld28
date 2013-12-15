#include <iostream>

#include <Box2D/Collision/Shapes/b2CircleShape.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>

#include "PhysicsWorldPosition.h"

PhysicsWorldPosition::PhysicsWorldPosition(b2Body *body, b2Vec2 size)
	: m_body(body)
	, m_destroyed(false)
	, m_size(size)
{
}


PhysicsWorldPosition::~PhysicsWorldPosition()
{
	b2World *world = m_body->GetWorld();
	m_destroyed = true;
	world->DestroyBody(m_body);
}

b2Vec2 PhysicsWorldPosition::position() const
{
	b2Vec2 position = m_body->GetPosition();
	position *= World::SCALE;
	return position;
}

void PhysicsWorldPosition::setPosition(const b2Vec2 &position)
{
	b2Vec2 newPosition(position.x / World::SCALE,
					   position.y / World::SCALE);

	m_body->SetTransform(newPosition, m_body->GetAngle());
	m_body->SetAwake(true);
}

float PhysicsWorldPosition::rotation() const
{
	return m_body->GetAngle() * 180 / M_PI;
}

void PhysicsWorldPosition::setRotation(float rotation)
{
	m_body->SetTransform(m_body->GetPosition(), rotation * M_PI / 180);
}

bool PhysicsWorldPosition::isDestroyed() const
{
	return m_destroyed;
}

b2Vec2 PhysicsWorldPosition::size() const
{
	return m_size;
}

void PhysicsWorldPosition::setSize(const b2Vec2 &size)
{
	m_size = size;
}

b2Fixture *PhysicsWorldPosition::createRectangularSensor(int xOffset, int yOffset, int width, int height)
{
	const float scaledXOffset = xOffset / World::SCALE;
	const float scaledYOffset = yOffset / World::SCALE;
	const float scaledWidth = width / World::SCALE;
	const float scaledHeight = height / World::SCALE;

	b2PolygonShape shape;
	shape.SetAsBox(scaledWidth / 2, scaledHeight / 2, b2Vec2(scaledXOffset, scaledYOffset), 0);

	b2FixtureDef fixtureDefinition;
	fixtureDefinition.shape = &shape;
	fixtureDefinition.isSensor = true;

	return m_body->CreateFixture(&fixtureDefinition);
}

b2Fixture *PhysicsWorldPosition::createCircularSensor(int radius)
{
	const float scaledRadius = radius / World::SCALE;

	b2CircleShape shape;
	shape.m_radius = scaledRadius;

	b2FixtureDef fixtureDefinition;
	fixtureDefinition.shape = &shape;
	fixtureDefinition.isSensor = true;

	return m_body->CreateFixture(&fixtureDefinition);
}

b2Fixture *PhysicsWorldPosition::createConeSensor(int length, int width)
{
	const float scaledLength = length / World::SCALE;
	const float scaledWidth = width / World::SCALE;

	b2Vec2 vertices[3];
	vertices[0].Set(0, 0);
	vertices[1].Set(scaledLength, -scaledWidth / 2);
	vertices[2].Set(scaledLength, scaledWidth / 2);

	b2PolygonShape shape;
	shape.Set(vertices, 3);

	b2FixtureDef fixtureDefinition;
	fixtureDefinition.shape = &shape;
	fixtureDefinition.isSensor = true;

	return m_body->CreateFixture(&fixtureDefinition);
}

b2Body *PhysicsWorldPosition::body() const
{
	return m_body;
}

void PhysicsWorldPosition::suspendCollision()
{
	b2Filter playerCollisionFilter;
	playerCollisionFilter.maskBits = 0;

	b2Fixture *fixture = m_body->GetFixtureList();

	while(fixture)
	{
		fixture->SetFilterData(playerCollisionFilter);
		fixture = fixture->GetNext();
	}
}
