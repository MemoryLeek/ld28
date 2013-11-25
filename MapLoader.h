#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <SFML/System/String.hpp>

class Map;

class MapLoader
{
	public:
		MapLoader();

		Map *load(const sf::String &fileName);
};

#endif // MAPLOADER_H
