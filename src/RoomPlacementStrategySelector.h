#ifndef ROOMPLACEMENTSTRATEGYSELECTOR_H
#define ROOMPLACEMENTSTRATEGYSELECTOR_H

#include <map>

#include "Direction.h"

class IRoomPlacementStrategy;

class RoomPlacementStrategySelector
{
	public:
		RoomPlacementStrategySelector();

		IRoomPlacementStrategy *select(const Direction::Value direction) const;

	private:
		std::map<Direction::Value, IRoomPlacementStrategy *> m_strategies;
};

#endif // ROOMPLACEMENTSTRATEGYSELECTOR_H
