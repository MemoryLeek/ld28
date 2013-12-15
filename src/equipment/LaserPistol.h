#ifndef LASERPISTOL_H
#define LASERPISTOL_H

#include "Weapon.h"

class World;
class Map;

class LaserPistol : public Weapon
{
	public:
		LaserPistol(const WorldPosition &position, World &world, Map &map);

		void fire() override;
};

#endif // LASERPISTOL_H
