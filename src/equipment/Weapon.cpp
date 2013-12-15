#include "Weapon.h"

Weapon::Weapon(const WorldPosition &position, World &world)
	: m_position(position)
	, m_world(world)
{
}

const WorldPosition &Weapon::position() const
{
	return m_position;
}

World &Weapon::world()
{
	return m_world;
}
