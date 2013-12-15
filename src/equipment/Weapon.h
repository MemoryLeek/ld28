#ifndef WEAPON_H
#define WEAPON_H

class Map;
class World;
class WorldPosition;

class Weapon
{
	public:
		Weapon(const WorldPosition &position, World &world, Map &map);

		virtual void fire() = 0;

	protected:
		const WorldPosition &position() const;

		Map &m_map;
		World &m_world;

	private:
		const WorldPosition &m_position;
};

#endif // WEAPON_H
