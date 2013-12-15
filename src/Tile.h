#ifndef TILE_H
#define TILE_H

#include <map>
#include <list>

#include "BinaryStream.h"
#include "DrawableObject.h"
#include "TileLayer.h"
#include "MapObject.h"

class Tile
{
	friend BinaryStream &operator >>(BinaryStream &stream, Tile &tile);

	public:
		sf::Image texture() const;

		bool isCollidable() const;
		bool isEmpty() const;

		MapObject mapObject() const;

	private:
		sf::Image m_texture;

		bool m_collidable;
		bool m_hasContent;

		MapObject m_mapObject;
};

#endif // TILE_H
