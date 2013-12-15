#ifndef MAPOBJECTFACTORY_H
#define MAPOBJECTFACTORY_H

class WorldObject;
class WorldPosition;

class IMapObjectFactory
{
	public:
		virtual WorldObject *create(WorldPosition *worldPosition) = 0;
};

template<class TMapObject>
class MapObjectFactory : public IMapObjectFactory
{
	public:
		WorldObject *create(WorldPosition *worldPosition) override
		{
			return new TMapObject(worldPosition);
		}
};

#endif // MAPOBJECTFACTORY_H
