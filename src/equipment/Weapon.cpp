#include "Weapon.h"
#include "World.h"
#include "Map.h"

Weapon::Weapon(const WorldPosition &position, const b2Filter &filter, World &world, Map &map)
	: m_position(position)
	, m_filter(filter)
	, m_world(world)
	, m_map(map)
{
}

const WorldPosition &Weapon::position() const
{
	return m_position;
}

const b2Filter &Weapon::filter() const
{
	return m_filter;
}
