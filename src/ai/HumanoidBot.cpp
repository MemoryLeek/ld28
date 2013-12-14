#include <iostream>

#include "HumanoidBot.h"

HumanoidBot::HumanoidBot(WorldPosition *position, const std::list<const WorldObject *> &enemies, const Pathfinder *pathfinder)
	: Bot(position, enemies, pathfinder)
	, m_target(NULL)
{
}

void HumanoidBot::onCollision(const WorldObject *other)
{
	std::cout << "HumanoidBot collided with another object." << std::endl;
}

void HumanoidBot::onTargetSpotted()
{
	const WorldObject *closestTarget = closestVisibleTarget();

	if(!m_target)
	{
		std::cout << "HumanoidBot: Target spotted, moving to target." << std::endl;
		m_target = closestTarget;
	}


	if(closestTarget != m_target)
	{
		std::cout << "HumanoidBot: Closer target found, changing." << std::endl;
	}

	moveTo(m_target->worldPosition().position());
}

void HumanoidBot::onPathEnd()
{
	std::cout << "HumanoidBot: End of path, target lost." << std::endl;
	m_target = nullptr;
}
