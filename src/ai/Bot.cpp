#include <SFML/Graphics/VertexArray.hpp>

#include "Bot.h"
#include "Pathfinder.h"
#include "PhysicsWorldPosition.h"
#include "RayCastResult.h"
#include "WorldObject.h"

#include "PathNode.h"

const float Bot::RAYCAST_INTERVAL = 1.f / 2.f;

Bot::Bot(WorldPosition *position, const std::list<const WorldObject *> &enemies, const Pathfinder *pathfinder)
	: DrawableObject(position, 32, 32)
	, m_enemies(enemies)
	, m_pathfinder(pathfinder)
	, m_lastPathfindingDestination(0, 0)
	, m_maxVisionDistance(10)
	, m_target(NULL)
{
	const PhysicsWorldPosition &physicsWorldPosition = (PhysicsWorldPosition &)worldPosition();

	m_body = physicsWorldPosition.body();
	m_body->SetFixedRotation(true);
}

void Bot::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if(m_target)
	{
		std::stack<b2Vec2> path = std::stack<b2Vec2>(m_path);

		sf::VertexArray debugpath(sf::LinesStrip, path.size());
		for(int i = 0; !path.empty(); i++)
		{
			const b2Vec2 &point = path.top();
			debugpath[i] = sf::Vector2f(point.x, point.y);
			debugpath[i].color = sf::Color::White;
			path.pop();
		}
		target.draw(debugpath);
	}
}

void Bot::update()
{
	if(m_rayCastTimer.getElapsedTime().asSeconds() > RAYCAST_INTERVAL)
	{
		m_target = findTarget();
		if(m_target)
		{
			const b2Vec2 targetPosition = m_target->worldPosition().position();

			if(b2Distance(m_lastPathfindingDestination, targetPosition) > 64)
			{
				const b2Vec2 originPoint = (m_path.empty()) ? worldPosition().position() : m_path.top();

				const std::stack<b2Vec2> newPath = m_pathfinder->find(originPoint, targetPosition);
				if(!newPath.empty())
				{
					m_path = newPath;
					m_lastPathfindingDestination = targetPosition;
				}
			}
		}

		m_rayCastTimer.restart();
	}

	PhysicsWorldPosition &myWorldPosition = static_cast<PhysicsWorldPosition &>(worldPosition());
	if(m_target)
	{
		const b2Vec2 myPosition = myWorldPosition.position();

		// If we have a path to follow
		if(!m_path.empty())
		{
			b2Vec2 nodePosition = m_path.top();
			while(b2Distance(myPosition, nodePosition) < 16 && m_path.size() > 1)
			{
				m_path.pop();
				nodePosition = m_path.top();
			}

			float angleToNextNode = atan2(myPosition.y - nodePosition.y,
										  myPosition.x - nodePosition.x);
			myWorldPosition.setRotation(angleToNextNode * 180 / M_PI);

			m_body->SetLinearVelocity(m_body->GetWorldVector(b2Vec2(-1, 0)));
		}
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
		const PhysicsWorldPosition *enemyWorldPosition = dynamic_cast<PhysicsWorldPosition*>(&enemyObject->worldPosition());
		assert(enemyWorldPosition); // Only physics objects are allowed in the enemy list

		///
		#warning Bot raycasting disabled, full map X-ray vision active
		return enemyObject;
		///

		// Only bother raycasting if the enemy is within range
		if(distanceTo(enemyObject) < m_maxVisionDistance)
		{
			const PhysicsWorldPosition &myWorldPosition = static_cast<PhysicsWorldPosition &>(worldPosition());
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
	b2Vec2 myPosition = worldPosition().position();
	b2Vec2 objectPosition = object->worldPosition().position();

	return b2Distance(myPosition, objectPosition) / World::SCALE;
}
