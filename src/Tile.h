#ifndef TILE_H
#define TILE_H

#include <map>
#include <list>

#include "BinaryStream.h"
#include "DrawableObject.h"
#include "TileLayer.h"

class Tile
{
	friend BinaryStream &operator >>(BinaryStream &stream, Tile &tile);

	public:
		sf::Image texture() const;

		bool isCollidable() const;

	private:
		sf::Image m_texture;

		bool m_collidable;
};

#endif // TILE_H
