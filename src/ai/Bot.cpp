#include <iostream>

#include <SFML/Graphics/VertexArray.hpp>

#include "Bot.h"
#include "Pathfinder.h"
#include "PhysicsWorldPosition.h"
#include "RayCastResult.h"
#include "WorldObject.h"

#include "PathNode.h"

Bot::Bot(WorldPosition *position, const std::list<const WorldObject *> &enemies, const Pathfinder *pathfinder)
	: DrawableObject(position)
	, m_enemies(enemies)
	, m_pathfinder(pathfinder)
	, m_maxVisionDistance(20)
{
	PhysicsWorldPosition &physicsWorldPosition = (PhysicsWorldPosition &)worldPosition();

	m_body = physicsWorldPosition.body();
	m_body->SetFixedRotation(true);

	m_hearingSensor = physicsWorldPosition.createCircularSensor(96);
	m_visionSensor = physicsWorldPosition.createConeSensor(m_maxVisionDistance * 32, m_maxVisionDistance * 24);
}

void Bot::onCollision(const WorldObject *other)
{
	std::cout << "Bot collided with another object." << std::endl;
}

void Bot::onSensorEnter(const b2Fixture *sensor, WorldObject *other)
{
	if(std::find(m_enemies.begin(), m_enemies.end(), other) == m_enemies.end())
	{
		return;
	}

	if(sensor == m_hearingSensor)
	{
		std::cout << "Bot hearing sensor triggered." << std::endl;
		m_trackedTargets.push_back(other);
		onTargetHeard(other);
	}
	else if(sensor == m_visionSensor)
	{
		std::cout << "Bot vision sensor triggered." << std::endl;
		if(hasVisionTo(other))
		{
			m_trackedTargets.push_back(other);
			onTargetSpotted(other);
		}
	}
}

void Bot::onSensorLeave(const b2Fixture *sensor, WorldObject *other)
{
	onSensorEnter(sensor, other);

	if(std::find(m_trackedTargets.begin(), m_trackedTargets.end(), other) != m_trackedTargets.end())
	{
		m_trackedTargets.remove(other);
	}
}

void Bot::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if(!m_path.empty())
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

bool Bot::update(int delta)
{
	if(m_trackedTargets.size() > 0)
	{
		for(WorldObject *target : m_trackedTargets)
		{
			if(hasVisionTo(target))
			{
				onTargetSpotted(target);
			}
		}
	}

	// If we have a path to follow
	if(m_path.size() > 1)
	{
		PhysicsWorldPosition &myWorldPosition = static_cast<PhysicsWorldPosition &>(worldPosition());
		const b2Vec2 &myPosition = myWorldPosition.position();

		b2Vec2 nodePosition = m_path.top();
		while(b2Distance(myPosition, nodePosition) < 16 && m_path.size() > 1)
		{
			m_path.pop();
			nodePosition = m_path.top();

			if(m_path.size() == 1)
			{
				onPathEnd();
			}
		}

		float angleToNextNode = atan2(nodePosition.y - myPosition.y,
									  nodePosition.x - myPosition.x);
		myWorldPosition.setRotation(angleToNextNode * 180 / M_PI);

		m_body->SetLinearVelocity(m_body->GetWorldVector(b2Vec2(1, 0)));
	}
	else
	{
		m_body->SetLinearVelocity(b2Vec2(0, 0));
	}

	return true;
}

bool Bot::moveTo(const b2Vec2 &position)
{
	const b2Vec2 originPoint = (m_path.empty()) ? worldPosition().position() : m_path.top();
	const std::stack<b2Vec2> newPath = m_pathfinder->find(originPoint, position);

	if(!newPath.empty())
	{
		m_path = newPath;
		return true;
	}

	return false;
}

float Bot::distanceTo(const WorldObject *object) const
{
	b2Vec2 myPosition = worldPosition().position();
	b2Vec2 objectPosition = object->worldPosition().position();

	return b2Distance(myPosition, objectPosition) / World::SCALE;
}

bool Bot::hasVisionTo(const WorldObject *object) const
{
	const PhysicsWorldPosition *enemyWorldPosition = dynamic_cast<PhysicsWorldPosition*>(&object->worldPosition());
	assert(enemyWorldPosition);

	const b2World *world = m_body->GetWorld();
	const b2Body *enemyBody = enemyWorldPosition->body();

	const b2Fixture *enemyFixture = enemyBody->GetFixtureList();
	while(enemyFixture->IsSensor())
	{
		enemyFixture = enemyFixture->GetNext();
	}

	RayCastResult rayCastResult;
	world->RayCast(&rayCastResult, m_body->GetPosition(), enemyBody->GetPosition());
	if(rayCastResult.fixture() == enemyFixture)
	{
		return true;
	}

	return false;
}
