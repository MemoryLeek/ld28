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

	const int width = tiledMap.GetTileWidth();
	const int height = tiledMap.GetTileHeight();

	for(int x = 0 ; x < width; x++)
	{
		for(int y = 0; y < height; y++)
		{
			sf::RenderTexture *renderTexture = new sf::RenderTexture();
			renderTexture->create(width, height);

			for(int i = 0; i < tiledMap.GetNumLayers(); i++)
			{
				const Tmx::Layer *layer = tiledMap.GetLayer(i);
				const Tmx::MapTile &mapTile = layer->GetTile(0, 0);
				const Tmx::Tileset *tileset = tiledMap.GetTileset(mapTile.tilesetId);
				const Tmx::Image *image = tileset->GetImage();

				const int w = image->GetWidth() / tileset->GetTileWidth();
				const int ty = mapTile.id / w;
				const int tx = mapTile.id - (ty * w);

				std::cout << tx << "x" << ty << std::endl;

				sf::String source = image->GetSource();
				sf::String path = sf::StringEx::format("resources/%1", source);

				sf::Rect<int> rect(x * width, y * height, width, height);
				sf::Texture texture;
				texture.loadFromFile(path, rect);

				std::cout << rect.left << ", " << rect.top << " - " << rect.width << "x" << rect.height << std::endl;

				sf::Sprite sprite(texture);

				renderTexture->draw(sprite);
			}

			renderTexture->display();

			const sf::Texture &composited = renderTexture->getTexture();
			const DrawableObject *mapObject = new DrawableObject(composited);

			map->addObject(mapObject);
		}
	}

	return map;
}
