#ifndef WEAPON_H
#define WEAPON_H

#include <Box2D/Dynamics/b2Fixture.h>

class Map;
class World;
class WorldPosition;

class Weapon
{
	public:
		Weapon(const WorldPosition &position, const b2Filter &filter, World &world, Map &map);

		virtual void fire() = 0;

	protected:
		const WorldPosition &position() const;
		const b2Filter &filter() const;

		Map &m_map;
		World &m_world;

	private:
		const WorldPosition &m_position;
		const b2Filter &m_filter;
};

#endif // WEAPON_H
