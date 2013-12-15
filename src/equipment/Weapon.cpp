#include "Weapon.h"
#include "World.h"
#include "Map.h"

Weapon::Weapon(const WorldPosition &position, World &world, Map &map)
	: m_position(position)
	, m_world(world)
	, m_map(map)
{
}

const WorldPosition &Weapon::position() const
{
	return m_position;
}
