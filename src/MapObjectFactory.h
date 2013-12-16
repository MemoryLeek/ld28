#ifndef MAPOBJECTFACTORY_H
#define MAPOBJECTFACTORY_H

#include <iostream>

#include "Direction.h"
#include "PositionFactory.h"
#include "Player.h"
#include "Room.h"

#include "equipment/LaserPistol.h"
#include "ai/HumanoidBot.h"
#include "objects/Door.h"

class WorldObject;
class WorldPosition;
class Map;
class Pathfinder;

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

			return object;
		}

	private:
		const PositionFactory &m_worldPositionFactory;
};

class SpawnFactory : public IMapObjectFactory
{
	public:
		SpawnFactory(const PositionFactory &worldPositionFactory, Player *player, Pathfinder *pathfinder, Map *map, World *world, b2Filter *projectileFilter, sf::SoundBuffer *stepSound)
			: m_worldPositionFactory(worldPositionFactory)
			, m_player(player)
			, m_pathfinder(pathfinder)
			, m_map(map)
			, m_world(world)
			, m_projectileFilter(projectileFilter)
			, m_stepSound(stepSound)
		{

		}

		WorldObject *create(const b2Vec2 &vector, const Direction::Value) const override
		{
			WorldPosition *position = m_worldPositionFactory.create(true, vector, TILE_SIZE, TILE_SIZE);
			LaserPistol *weapon = new LaserPistol(*position, *m_projectileFilter, *m_world, *m_map);
			HumanoidBot *bot = new HumanoidBot(position, { m_player }, m_pathfinder, *m_stepSound, *m_map);
			bot->setWeapon(weapon);

			return bot;
		}

	private:
		const PositionFactory &m_worldPositionFactory;

		Player *m_player;
		Pathfinder *m_pathfinder;
		Map *m_map;
		World *m_world;

		b2Filter *m_projectileFilter;
		sf::SoundBuffer *m_stepSound;
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
