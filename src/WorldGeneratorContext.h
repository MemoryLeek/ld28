#ifndef WORLDGENERATORCONTEXT_H
#define WORLDGENERATORCONTEXT_H

#include <set>

#include "Direction.h"
#include "Room.h"

class RoomPlacementStrategySelector;

class WorldGeneratorContext
{
	public:
		WorldGeneratorContext(std::set<int> &generatedRooms, std::set<Coordinate> &generatedTiles, RoomPlacementStrategySelector &selector);
		WorldGeneratorContext(const WorldGeneratorContext &other, const Direction::Value direction, const int x, const int y);

		WorldGeneratorContext fork(const Room &first, const Room &second, const Direction::Value direction);

		Direction::Value direction() const;
		Direction::Value reverse() const;

		bool isRoomGenerated(const Room &room) const;
		void markAsGenerated(const Room &room);

		bool isTileGenerated(const Coordinate &tile) const;
		void markAsGenerated(const Coordinate &tile);

		bool canFitRoom(const Room &first, const Room &second, const Direction::Value direction) const;

		int x() const;
		int y() const;

	private:
		std::set<int> &m_generatedRooms;
		std::set<Coordinate> &m_generatedTiles;

		RoomPlacementStrategySelector &m_selector;
		Direction::Value m_direction;

		int m_x;
		int m_y;
};

#endif // WORLDGENERATORCONTEXT_H
