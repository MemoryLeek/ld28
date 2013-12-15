#ifndef MAPOBJECTRESOLVER_H
#define MAPOBJECTRESOLVER_H

#include <map>

class IMapObjectFactory;
class PositionFactory;

class MapObjectResolver
{
	public:
		MapObjectResolver(const PositionFactory &positionFactory);

		IMapObjectFactory *resolve(const int id) const;

	private:
		std::map<int, IMapObjectFactory *> m_factories;
};

#endif // MAPOBJECTRESOLVER_H
