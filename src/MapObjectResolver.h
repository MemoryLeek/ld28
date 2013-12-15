#ifndef MAPOBJECTRESOLVER_H
#define MAPOBJECTRESOLVER_H

#include <map>

class IMapObjectFactory;

class MapObjectResolver
{
	public:
		MapObjectResolver();

		IMapObjectFactory *resolve(const int id) const;

	private:
		std::map<int, IMapObjectFactory *> m_factories;
};

#endif // MAPOBJECTRESOLVER_H
