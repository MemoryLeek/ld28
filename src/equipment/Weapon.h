#ifndef WEAPON_H
#define WEAPON_H

#include "World.h"
#include "WorldPosition.h"

class Weapon
{
	public:
		Weapon(const WorldPosition &position, World &world);

		virtual void fire() = 0;

	protected:
		const WorldPosition &position() const;
		World &world();

	private:
		const WorldPosition &m_position;
		World &m_world;
};

#endif // WEAPON_H
