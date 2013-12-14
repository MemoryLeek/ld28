#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <utility>

#include "Tile.h"
#include "Direction.h"
#include "MapType.h"

using Coordinate = std::pair<int, int>;

const int TILE_SIZE = 32;

class Room
{
	friend BinaryStream &operator >>(BinaryStream &stream, Room &room);

	public:
		Room();

		MapType::Value type() const;

		std::map<Coordinate, Tile> tiles() const;
		std::map<Direction::Value, Coordinate> entrances() const;

		Coordinate entrance(const Direction::Value direction) const;

		int weight() const;
		int id() const;
		int width() const;
		int height() const;

		static bool isStart(const Room &room);
		static bool isEnd(const Room &room);

	private:
		MapType::Value m_type;

		std::map<Coordinate, Tile> m_tiles;
		std::map<Direction::Value, Coordinate> m_entrances;

		int m_id;
		int m_width;
		int m_height;
};

#endif // ROOM_H
