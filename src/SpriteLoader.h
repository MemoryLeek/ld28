#ifndef SPRITELOADER_H
#define SPRITELOADER_H

#include <SFML/System/String.hpp>

class SpriteBundle;

class SpriteLoader
{
	public:
		SpriteBundle *load(const sf::String &fileName);
};

#endif // SPRITELOADER_H
