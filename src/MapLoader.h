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
class Player;

namespace sf
{
	class SoundBuffer;
}

class MapLoader
{
	public:
		MapLoader(World *world, Pathfinder *pathfinder, Player *player, b2Filter *projectileFilter, sf::SoundBuffer *stepSound);

		RoomObject *load(const Room &room, WorldGeneratorContext &context, Map *map);

	private:
		World *m_world;
		Pathfinder *m_pathfinder;
		Player *m_player;
		b2Filter *m_projectileFilter;
		sf::SoundBuffer *m_stepSound;
};

#endif // MAPLOADER_H
