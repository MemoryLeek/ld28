#include <map>

#include "MapType.h"
#include "RoomSelectorPredicate.h"
#include "Room.h"

RoomSelectorPredicate::RoomSelectorPredicate(const Direction::Value direction, const WorldGeneratorContext &context)
	: m_direction(direction)
	, m_context(context)
{

}

bool RoomSelectorPredicate::predicate(const Room &room) const
{
	std::map<Direction::Value, Coordinate> entrances = room.entrances();
	std::map<Direction::Value, Coordinate>::iterator iterator = entrances.find(m_direction);

	return !m_context.isRoomGenerated(room) &&
		iterator != entrances.end() &&
		room.type() == MapType::Normal;
}
