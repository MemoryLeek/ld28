#ifndef MAPOBJECTRESOLVER_H
#define MAPOBJECTRESOLVER_H

#include <map>

class IMapObjectFactory;
class PositionFactory;
class Player;
class Pathfinder;
class Map;
class World;

namespace sf
{
	class SoundBuffer;
}

class MapObjectResolver
{
	public:
		MapObjectResolver(const PositionFactory &positionFactory
			, Player *player
			, Pathfinder *pathfinder
			, Map *map
			, World *world
			, b2Filter *botFilter
			, b2Filter *projectileFilter
			, sf::SoundBuffer *stepSound);

		IMapObjectFactory *resolve(const int id) const;

	private:
		std::map<int, IMapObjectFactory *> m_factories;
};

#endif // MAPOBJECTRESOLVER_H
