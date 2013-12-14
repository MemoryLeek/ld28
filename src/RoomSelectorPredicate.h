#ifndef ROOMSELECTORPREDICATE_H
#define ROOMSELECTORPREDICATE_H

#include "Direction.h"
#include "WorldGeneratorContext.h"

class RoomSelectorPredicate
{
	public:
		RoomSelectorPredicate(const Direction::Value direction, const WorldGeneratorContext &context, const Room &room);

		bool predicate(const Room &room) const;

	private:
		const Direction::Value m_direction;
		const WorldGeneratorContext m_context;
		const Room &m_room;
};

#endif // ROOMSELECTORPREDICATE_H
