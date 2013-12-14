#ifndef WORLDGENERATOR_H
#define WORLDGENERATOR_H

#include <SFML/System/String.hpp>

class WorldGeneratorContext;
class RoomObject;
class MapLoader;
class Map;

class WorldGenerator
{
	public:
		WorldGenerator(MapLoader *mapLoader, const sf::String &fileName);

		Map *generate();

	private:
		RoomObject *generate(const Room &room, std::vector<Room> &rooms, WorldGeneratorContext &context, Map *map);

		MapLoader *m_mapLoader;
		sf::String m_fileName;
};

#endif // WORLDGENERATOR_H
