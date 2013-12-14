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

MapLoader::MapLoader(World *world, Pathfinder *pathfinder)
	: m_world(world)
	, m_pathfinder(pathfinder)
{

}

RoomObject *MapLoader::load(const Room &room, const WorldGeneratorContext &context)
{
	RoomObject *map = new RoomObject();

	std::map<Coordinate, Tile> tiles = room.tiles();
	std::map<Coordinate, Tile>::const_iterator iterator = tiles.begin();

	for(; iterator != tiles.end(); iterator++)
	{
		const Coordinate &coordinate = iterator->first;
		const Tile &tile = iterator->second;

		const bool collidable = tile.isCollidable();

		const int x = coordinate.first + context.x();
		const int y = coordinate.second + context.y();

		const PositionFactory factory(m_world);
		const b2Vec2 position(x * TILE_SIZE, y * TILE_SIZE);

		sf::Image image = tile.texture();
		sf::Texture texture;
		texture.loadFromImage(image);

		WorldPosition *worldPosition = factory.create(collidable, position, TILE_SIZE, TILE_SIZE);
		TileObject *tileObject = new TileObject(worldPosition, texture);

		map->addObject(tileObject);

		if(!collidable)
		{
			m_pathfinder->setWalkable(x, y);
		}
	}

	return map;
}
