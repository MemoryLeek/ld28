#include <iostream>
#include <unordered_map>

#include <TmxParser/Tmx.h>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "ai/Pathfinder.h"
#include "Tile.h"
#include "MapLoader.h"
#include "Map.h"
#include "PhysicsWorldPosition.h"
#include "StaticWorldPosition.h"
#include "StringEx.h"
#include "World.h"
#include "PositionFactory.h"
#include "RoomLookupLoader.h"
#include "TileObject.h"

MapLoader::MapLoader(World *world, Pathfinder *pathfinder)
	: m_world(world)
	, m_pathfinder(pathfinder)
{

}

Map *MapLoader::load(const sf::String &fileName)
{
	RoomLookupLoader loader(fileName);
	RoomLookup *lookup = loader.load();
	Map *map = new Map();

	for(const RoomObject &room : lookup->rooms())
	{
		std::map<Coordinate, Tile> tiles = room.tiles();
		std::map<Coordinate, Tile>::const_iterator iterator = tiles.begin();

		for(; iterator != tiles.end(); iterator++)
		{
			const Coordinate &coordinate = iterator->first;
			const Tile &tile = iterator->second;
			const PositionFactory factory(m_world);
			const b2Vec2 position(coordinate.first * TILE_SIZE, coordinate.second * TILE_SIZE);

			const bool collidable = tile.isCollidable();

			sf::Image image = tile.texture();
			sf::Texture texture;
			texture.loadFromImage(image);

			WorldPosition *worldPosition = factory.create(collidable, position, TILE_SIZE, TILE_SIZE);
			TileObject *tileObject = new TileObject(worldPosition, texture);

			map->addObject(tileObject);

			if(!collidable)
			{
				m_pathfinder->setWalkable(coordinate.first, coordinate.second);
			}
		}

		// For now, to retain old behavior

		break;
	}

	return map;
}
