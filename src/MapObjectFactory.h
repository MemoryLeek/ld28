#ifndef MAPOBJECTFACTORY_H
#define MAPOBJECTFACTORY_H

#include <iostream>

#include "Direction.h"
#include "PositionFactory.h"
#include "Room.h"

#include "objects/Door.h"

class WorldObject;
class WorldPosition;

class IMapObjectFactory
{
	public:
		virtual WorldObject *create(const b2Vec2 &vector, const Direction::Value direction) const = 0;
};

template<class TMapObject>
class MapObjectFactory : public IMapObjectFactory
{
	public:
		MapObjectFactory(const PositionFactory &worldPositionFactory)
			: m_worldPositionFactory(worldPositionFactory)
		{

		}

		WorldObject *create(const b2Vec2 &vector, const Direction::Value) const override
		{
			WorldPosition *position = m_worldPositionFactory.create(true, vector, TILE_SIZE, TILE_SIZE);
			WorldObject *object = new TMapObject(position);

			std::cout << "Creating something else at " << vector.x << "x" << vector.y << std::endl;

			return object;
		}

	private:
		const PositionFactory &m_worldPositionFactory;
};

template<>
class MapObjectFactory<Door> : public IMapObjectFactory
{
	public:
		MapObjectFactory(const PositionFactory &worldPositionFactory)
			: m_worldPositionFactory(worldPositionFactory)
		{

		}

		WorldObject *create(const b2Vec2 &vector, const Direction::Value direction) const override
		{
			switch(direction)
			{
				case Direction::Left:
				{
					WorldPosition *position = m_worldPositionFactory.create(true, vector + b2Vec2(0, 16), TILE_SIZE, TILE_SIZE * 2);
					WorldObject *object = new Door(position, direction, "resources/door-left.spb");

					return object;
				}

				case Direction::Right:
				{
					WorldPosition *position = m_worldPositionFactory.create(true, vector + b2Vec2(0, 16), TILE_SIZE, TILE_SIZE * 2);
					WorldObject *object = new Door(position, direction, "resources/door-right.spb");

					return object;
				}

				case Direction::Top:
				{
					WorldPosition *position = m_worldPositionFactory.create(true, vector + b2Vec2(16, 0), TILE_SIZE * 2, TILE_SIZE);
					WorldObject *object = new Door(position, direction, "resources/door-top.spb");

					return object;
				}

				case Direction::Bottom:
				{
					WorldPosition *position = m_worldPositionFactory.create(true, vector + b2Vec2(16, 0), TILE_SIZE * 2, TILE_SIZE);
					WorldObject *object = new Door(position, direction, "resources/door-bottom.spb");

					return object;
				}

				default:
				{
					return 0;
				}
			}
		}

	private:
		const PositionFactory &m_worldPositionFactory;
};

#endif // MAPOBJECTFACTORY_H
