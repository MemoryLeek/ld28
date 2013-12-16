#include "MapObjectFactory.h"
#include "MapObjectResolver.h"
#include "PositionFactory.h"

#include "objects/Door.h"
#include "objects/TreasureContainer.h"

MapObjectResolver::MapObjectResolver(const PositionFactory &positionFactory
	, Player *player
	, Pathfinder *pathfinder
	, Map *map
	, World *world
	, b2Filter *botFilter, b2Filter *projectileFilter
	, sf::SoundBuffer *stepSound)
{
	m_factories =
	{
		{ 0, new MapObjectFactory<Door>(positionFactory) },
		{ 1, new MapObjectFactory<TreasureContainer>(positionFactory) },
		{ 2, new SpawnFactory(positionFactory, player, pathfinder, map, world, botFilter, projectileFilter, stepSound) }
	};
}

IMapObjectFactory *MapObjectResolver::resolve(const int id) const
{
	return m_factories.at(id);
}
