#include "MapObjectFactory.h"
#include "MapObjectResolver.h"

#include "objects/Door.h"

MapObjectResolver::MapObjectResolver()
{
	m_factories =
	{
		{ 0, new MapObjectFactory<Door>() }
	};
}

IMapObjectFactory *MapObjectResolver::resolve(const int id) const
{
	return m_factories.at(id);
}
