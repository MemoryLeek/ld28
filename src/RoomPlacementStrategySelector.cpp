#include "RoomPlacementStrategySelector.h"
#include "RoomPlacementStrategy.h"

RoomPlacementStrategySelector::RoomPlacementStrategySelector()
{
	m_strategies =
	{
		{ Direction::Left, new RoomPlacementStrategy<Direction::Left>() },
		{ Direction::Right, new RoomPlacementStrategy<Direction::Right>() },
		{ Direction::Top, new RoomPlacementStrategy<Direction::Top>() },
		{ Direction::Bottom, new RoomPlacementStrategy<Direction::Bottom>() }
	};
}

IRoomPlacementStrategy *RoomPlacementStrategySelector::select(const Direction::Value direction) const
{
	return m_strategies.at(direction);
}
