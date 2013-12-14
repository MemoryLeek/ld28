#include <map>

#include <SFML/Graphics/Rect.hpp>

#include "MapType.h"
#include "RoomSelectorPredicate.h"
#include "CoordinateRect.h"
#include "Room.h"

RoomSelectorPredicate::RoomSelectorPredicate(const Direction::Value direction, const WorldGeneratorContext &context, const Room &room)
	: m_direction(direction)
	, m_context(context)
	, m_room(room)
{

}

bool RoomSelectorPredicate::predicate(const Room &room) const
{
	const Direction::Value reverse = Direction::reverse(m_direction);
	const std::map<Direction::Value, Coordinate> entrances = room.entrances();
	const std::map<Direction::Value, Coordinate>::const_iterator iterator = entrances.find(reverse);

	return !m_context.isRoomGenerated(room) &&
		iterator != entrances.end() &&
		room.type() == MapType::Normal &&
		m_context.canFitRoom(m_room, room, m_direction);
}
