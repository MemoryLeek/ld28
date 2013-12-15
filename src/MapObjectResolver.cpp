#include "MapObjectFactory.h"
#include "MapObjectResolver.h"
#include "PositionFactory.h"

#include "objects/Door.h"
#include "objects/TreasureContainer.h"

MapObjectResolver::MapObjectResolver(const PositionFactory &positionFactory)
{
	m_factories =
	{
		{ 0, new MapObjectFactory<Door>(positionFactory) },
		{ 1, new MapObjectFactory<TreasureContainer>(positionFactory) }
	};
}

IMapObjectFactory *MapObjectResolver::resolve(const int id) const
{
	return m_factories.at(id);
}
