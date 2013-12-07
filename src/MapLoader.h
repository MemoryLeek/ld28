#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <unordered_map>

#include <TmxParser/Tmx.h>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>

using TextureCache = std::unordered_map<int, sf::Texture *>;
using TextureCacheIterator = TextureCache::iterator;

class Map;
class Pathfinder;
class World;

class MapLoader
{
	public:
		MapLoader(World *world, Pathfinder *pathfinder);

		Map *load(const sf::String &fileName);

	private:
		sf::Texture *tryGetTexture(const int id, const Tmx::Image *image, TextureCache &cache);

		World *m_world;
		Pathfinder *m_pathfinder;
};

#endif // MAPLOADER_H
