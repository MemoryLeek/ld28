#include <iostream>

#include "HumanoidBot.h"

#include "equipment/Weapon.h"

HumanoidBot::HumanoidBot(WorldPosition *position, const std::list<const WorldObject *> &enemies, const Pathfinder *pathfinder, const sf::SoundBuffer &stepSound, Map &map)
	: Bot(100, position, enemies, pathfinder, map)
	, m_target(NULL)
	, m_stepSound(stepSound)
	, m_stepTimer(0)
	, m_fireTimer(0)
{
	m_stepSound.setAttenuation(0.05f);
}

void HumanoidBot::onUpdate(int delta)
{
	if(isMoving())
	{
		m_stepTimer += delta;
	}

	if(m_stepTimer > 500)
	{
		const b2Vec2 &position = worldPosition().position();
		m_stepSound.setPosition(position.x, position.y, 0);
		m_stepSound.play();
		m_stepTimer = 0;
	}

	m_fireTimer += delta;

	if(m_target && m_fireTimer > 500 && hasVisionTo(m_target))
	{
		weapon()->fire();
		m_fireTimer = 0;
	}
}

void HumanoidBot::onTargetSpotted(const WorldObject *target)
{
	if(!m_target)
	{
		std::cout << "HumanoidBot: Target spotted, moving to target." << std::endl;
		m_target = target;
	}


	if(target != m_target && distanceTo(target) < distanceTo(m_target))
	{
		std::cout << "HumanoidBot: Spotted a closer target, changing." << std::endl;
	}

	moveTo(m_target->worldPosition().position());
}

void HumanoidBot::onTargetNoLongerVisible(const WorldObject *target)
{
	if(target == m_target)
	{
		std::cout << "HumanoidBot: Lost target, moving to last known position." << std::endl;
		pathfind(worldPosition().position(), target->worldPosition().position());
		m_target = nullptr;
	}
}

void HumanoidBot::onTargetHeard(const WorldObject *target)
{
	if(!m_target)
	{
		std::cout << "HumanoidBot: Target heard, moving to target." << std::endl;
		m_target = target;
	}

	if(target != m_target && distanceTo(target) < distanceTo(m_target))
	{
		std::cout << "HumanoidBot: Heard a closer target, changing." << std::endl;
	}

	pathfindTo(m_target->worldPosition().position());
}

void HumanoidBot::onPathEnd()
{

}
