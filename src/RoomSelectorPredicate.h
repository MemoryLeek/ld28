#ifndef ROOMSELECTORPREDICATE_H
#define ROOMSELECTORPREDICATE_H

#include "Direction.h"
#include "WorldGeneratorContext.h"

class RoomSelectorPredicate
{
	public:
		RoomSelectorPredicate(const Direction::Value direction, const WorldGeneratorContext &context);

		bool predicate(const Room &room) const;

	private:
		Direction::Value m_direction;
		WorldGeneratorContext m_context;
};

#endif // ROOMSELECTORPREDICATE_H
