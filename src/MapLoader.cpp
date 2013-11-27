#include <iostream>
#include <unordered_map>

#include <TmxParser/Tmx.h>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "TileObject.h"
#include "MapLoader.h"
#include "Map.h"
#include "PhysicsWorldPosition.h"
#include "StaticWorldPosition.h"
#include "StringEx.h"
#include "World.h"

MapLoader::MapLoader()
{

}

Map *MapLoader::load(const sf::String &fileName, World &world)
{
	Tmx::Map tiledMap;
	tiledMap.ParseFile(fileName);

	Map *map = new Map();
	TextureCache cache;

	const int width = tiledMap.GetWidth();
	const int height = tiledMap.GetHeight();
	const int tileWidth = tiledMap.GetTileWidth();
	const int tileHeight = tiledMap.GetTileHeight();

	for(int x = 0 ; x < width; x++)
	{
		for(int y = 0; y < height; y++)
		{
			const Tmx::Layer *collisionLayer = tiledMap.GetLayer(TileObject::Collision);
			const Tmx::MapTile &currentCollisionTile = collisionLayer->GetTile(x, y);
			bool isWall = (currentCollisionTile.id == 0) ? false : true;

			WorldPosition *worldPosition;
			if(isWall)
			{
				worldPosition = world.createBox(b2Vec2(x * tileWidth, y * tileHeight), tileWidth, tileHeight);
			}
			else
			{
				worldPosition = new StaticWorldPosition(b2Vec2(x * tileWidth, y * tileHeight));
			}

			TileObject *tile = new TileObject(worldPosition, tileWidth, tileHeight);

			for(int i = 0; i < tiledMap.GetNumLayers(); i++)
			{
				const Tmx::Layer *layer = tiledMap.GetLayer(i);
				const Tmx::MapTile &mapTile = layer->GetTile(x, y);

				if(mapTile.id > 0)
				{
					const Tmx::Tileset *tileset = tiledMap.GetTileset(mapTile.tilesetId);
					const Tmx::Image *image = tileset->GetImage();

					const int tw = image->GetWidth() / tileWidth;
					const int ty = mapTile.id / tw;
					const int tx = mapTile.id - (ty * tw);

					const sf::Texture *source = tryGetTexture(mapTile.tilesetId, image, cache);
					const sf::Rect<int> rect(tx * tileWidth, ty * tileHeight, tileWidth, tileHeight);

					TileLayer tileLayer(source, rect);

					tile->addLayer(tileLayer);
				}
			}

			map->addObject(tile);
		}
	}

	return map;
}

sf::Texture *MapLoader::tryGetTexture(const int id, const Tmx::Image *image, TextureCache &cache)
{
	TextureCacheIterator iterator = cache.find(id);

	if(iterator == cache.end())
	{
		std::cout << "Loading tileset" << std::endl;

		sf::String source = image->GetSource();
		sf::String path = sf::StringEx::format("resources/%1", source);
		sf::Texture *texture = new sf::Texture();
		texture->loadFromFile(path);

		cache[id] = texture;

		return texture;
	}
	else
	{
		std::cout << "Tileset already loaded" << std::endl;

		return iterator->second;
	}
}
