#include <iostream>

#include <SFML/Graphics/RenderTarget.hpp>

#include "Tile.h"
#include "RenderProxy.h"

sf::Image Tile::texture() const
{
	return m_texture;
}

bool Tile::isCollidable() const
{
	return m_collidable;
}

BinaryStream &operator >>(BinaryStream &stream, Tile &tile)
{
	unsigned int size = 0;

	stream >> tile.m_collidable;
	stream >> size;

	char *data = stream.read(size);

	sf::Image &texture = tile.m_texture;
	texture.loadFromMemory(data, size);

	return stream;
}
