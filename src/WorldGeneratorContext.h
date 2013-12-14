#ifndef WORLDGENERATORCONTEXT_H
#define WORLDGENERATORCONTEXT_H

#include <set>

#include "Direction.h"

class Room;
class RoomPlacementStrategySelector;

class WorldGeneratorContext
{
	public:
		WorldGeneratorContext(std::set<int> &generatedRooms, RoomPlacementStrategySelector &selector);
		WorldGeneratorContext(const WorldGeneratorContext &other, const Direction::Value direction, const int x, const int y);

		WorldGeneratorContext fork(const Room &current, const Room &next, const Direction::Value direction);

		Direction::Value direction() const;
		Direction::Value reverse() const;

		bool isRoomGenerated(const Room &room) const;
		void markAsGenerated(const Room &room);

		int x() const;
		int y() const;

	private:
		std::set<int> &m_generatedRooms;

		RoomPlacementStrategySelector &m_selector;
		Direction::Value m_direction;

		int m_x;
		int m_y;
};

#endif // WORLDGENERATORCONTEXT_H
