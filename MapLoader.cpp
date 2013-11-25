#include <iostream>

#include <TmxParser/Tmx.h>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "DrawableObject.h"
#include "MapLoader.h"
#include "Map.h"
#include "StringEx.h"

MapLoader::MapLoader()
{

}

Map *MapLoader::load(const sf::String &fileName)
{
	Tmx::Map tiledMap;
	tiledMap.ParseFile(fileName);

	Map *map = new Map();

	const int width = tiledMap.GetWidth();
	const int height = tiledMap.GetHeight();
	const int tileWidth = tiledMap.GetTileWidth();
	const int tileHeight = tiledMap.GetTileHeight();

	for(int x = 0 ; x < width; x++)
	{
		for(int y = 0; y < height; y++)
		{
			sf::RenderTexture *renderTexture = new sf::RenderTexture();
			renderTexture->create(tileWidth, tileHeight);

			for(int i = 0; i < tiledMap.GetNumLayers(); i++)
			{
				const Tmx::Layer *layer = tiledMap.GetLayer(i);
				const Tmx::MapTile &mapTile = layer->GetTile(x, y);
				const Tmx::Tileset *tileset = tiledMap.GetTileset(mapTile.tilesetId);
				const Tmx::Image *image = tileset->GetImage();

				const int w = image->GetWidth() / tileset->GetTileWidth();
				const int ty = mapTile.id / w;
				const int tx = mapTile.id - (ty * w);

				std::cout << tx << "x" << ty << std::endl;

				sf::String source = image->GetSource();
				sf::String path = sf::StringEx::format("resources/%1", source);

				sf::Rect<int> rect(tx * tileWidth, ty * tileHeight, tileWidth, tileHeight);
				sf::Texture texture;
				texture.loadFromFile(path, rect);

				std::cout << rect.left << ", " << rect.top << " - " << rect.width << "x" << rect.height << std::endl;

				sf::Sprite sprite(texture);

				renderTexture->draw(sprite);
			}

			renderTexture->display();

			const sf::Texture &composited = renderTexture->getTexture();
			const DrawableObject *mapObject = new DrawableObject(x * tileWidth, y * tileWidth, composited);

			map->addObject(mapObject);
		}
	}

	return map;
}
