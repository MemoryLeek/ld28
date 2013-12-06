#include <iostream>

#include "Bot.h"
#include "PhysicsWorldPosition.h"
#include "RayCastResult.h"
#include "WorldObject.h"

const float Bot::RAYCAST_INTERVAL = 1.f / 2.f;

Bot::Bot(WorldPosition *position, const std::list<const WorldObject *> enemies)
	: DrawableObject(position, 32, 32)
	, m_enemies(enemies)
	, m_maxVisionDistance(10)
	, m_target(NULL)
{
	m_body = static_cast<PhysicsWorldPosition*>(worldPosition())->body();
	m_body->SetFixedRotation(true);
}

void Bot::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
}

void Bot::update()
{
	if(m_rayCastTimer.getElapsedTime().asSeconds() > RAYCAST_INTERVAL)
	{
		m_target = findTarget();
		m_rayCastTimer.restart();
	}

	PhysicsWorldPosition *myWorldPosition = static_cast<PhysicsWorldPosition*>(worldPosition());
	if(m_target)
	{

		b2Vec2 myPosition = myWorldPosition->position();
		b2Vec2 targetPosition = m_target->worldPosition()->position();

		float angleToTarget = atan2(myPosition.y - targetPosition.y,
									myPosition.x - targetPosition.x);
		myWorldPosition->setRotation(angleToTarget * 180 / M_PI);

		m_body->SetLinearVelocity(m_body->GetWorldVector(b2Vec2(-1, 0)));
	}
	else
	{
		m_body->SetLinearVelocity(b2Vec2(0, 0));
	}
}

const WorldObject *Bot::findTarget()
{
	const WorldObject *target = NULL;

	for(const WorldObject *enemyObject : m_enemies)
	{
		const PhysicsWorldPosition *enemyWorldPosition = dynamic_cast<PhysicsWorldPosition*>(enemyObject->worldPosition());
		assert(enemyWorldPosition); // Only physics objects are allowed in the enemy list

		// Only bother raycasting if the enemy is within range
		if(distanceTo(enemyObject) < m_maxVisionDistance)
		{
			const PhysicsWorldPosition *myWorldPosition = static_cast<PhysicsWorldPosition*>(worldPosition());
			const b2World *world = m_body->GetWorld();

			const b2Body *enemyBody = enemyWorldPosition->body();
			const b2Fixture *enemyFixture = enemyBody->GetFixtureList();

			RayCastResult rayCastResult;
			world->RayCast(&rayCastResult, m_body->GetPosition(), enemyBody->GetPosition());
			if(rayCastResult.fixture() == enemyFixture)
			{
				if(!target || distanceTo(enemyObject) < distanceTo(target))
				{
					target = enemyObject;
				}
			}
		}
	}

	return target;
}

float Bot::distanceTo(const WorldObject *object) const
{
	b2Vec2 myPosition = worldPosition()->position();
	b2Vec2 objectPosition = object->worldPosition()->position();

	return b2Distance(myPosition, objectPosition) / World::SCALE;
}
