#include <iostream>
#include <unordered_map>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "ai/Pathfinder.h"

#include "Tile.h"
#include "MapLoader.h"
#include "RoomObject.h"
#include "PhysicsWorldPosition.h"
#include "StaticWorldPosition.h"
#include "StringEx.h"
#include "World.h"
#include "PositionFactory.h"
#include "RoomLookupLoader.h"
#include "TileObject.h"
#include "WorldGeneratorContext.h"
#include "MapObjectResolver.h"
#include "MapObjectFactory.h"

MapLoader::MapLoader(World *world, Pathfinder *pathfinder, Player *player, b2Filter *botFilter, b2Filter *projectileFilter, sf::SoundBuffer *stepSound)
	: m_world(world)
	, m_pathfinder(pathfinder)
	, m_player(player)
	, m_botFilter(botFilter)
	, m_projectileFilter(projectileFilter)
	, m_stepSound(stepSound)
{

}

RoomObject *MapLoader::load(const Room &room, WorldGeneratorContext &context, Map *map)
{
	RoomObject *roomObject = new RoomObject();

	std::map<Coordinate, Tile> tiles = room.tiles();
	std::map<Coordinate, Tile>::const_iterator iterator = tiles.begin();

	for(; iterator != tiles.end(); iterator++)
	{
		const Coordinate &coordinate = iterator->first;
		const Tile &tile = iterator->second;
		const MapObject &mapObject = tile.mapObject();

		const bool isCollidable = tile.isCollidable();
		const bool isEmpty = tile.isEmpty();

		const int x = coordinate.first + context.x();
		const int y = coordinate.second + context.y();
		const int id = mapObject.id();

		const PositionFactory factory(m_world);
		const MapObjectResolver resolver(factory, m_player, m_pathfinder, map, m_world, m_botFilter, m_projectileFilter, m_stepSound);
		const Direction::Value direction = (Direction::Value)mapObject.direction();
		const b2Vec2 position(x * TILE_SIZE, y * TILE_SIZE);

		sf::Image image = tile.texture();
		sf::Texture texture;
		texture.loadFromImage(image);

		WorldPosition *worldPosition = factory.create(isCollidable, position, TILE_SIZE, TILE_SIZE);
		TileObject *tileObject = new TileObject(worldPosition, texture);

		roomObject->addObject(tileObject);

		if(id >= 0)
		{
			IMapObjectFactory *mapObjectFactory = resolver.resolve(id);
			WorldObject *worldObject = mapObjectFactory->create(position, direction);

			map->addObject(worldObject);
		}

		if(!isCollidable)
		{
			m_pathfinder->setWalkable(x, y);
		}

		if(!isEmpty)
		{
			context.markAsGenerated(coordinate);
		}
	}

	roomObject->done();

	return roomObject;
}
