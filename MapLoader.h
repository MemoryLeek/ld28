#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <unordered_map>

#include <TmxParser/Tmx.h>

#include <SFML/Graphics/Image.hpp>
#include <SFML/System/String.hpp>

using ImageCache = std::unordered_map<int, sf::Image *>;
using ImageCacheIterator = ImageCache::iterator;

class Map;

class MapLoader
{
	public:
		MapLoader();

		Map *load(const sf::String &fileName);

	private:
		sf::Image *tryGetImage(const int id, const Tmx::Image *image, ImageCache &cache);
};

#endif // MAPLOADER_H
