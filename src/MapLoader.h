#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <unordered_map>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>

using TextureCache = std::unordered_map<int, sf::Texture *>;
using TextureCacheIterator = TextureCache::iterator;

class WorldGeneratorContext;
class RoomObject;
class Pathfinder;
class World;
class Room;

class MapLoader
{
	public:
		MapLoader(World *world, Pathfinder *pathfinder);

		RoomObject *load(const Room &room, const WorldGeneratorContext &context);

	private:
		World *m_world;
		Pathfinder *m_pathfinder;
};

#endif // MAPLOADER_H
