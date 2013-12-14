#ifndef ROOMLOOKUP_H
#define ROOMLOOKUP_H

#include <list>

#include <SFML/Graphics/Drawable.hpp>

#include "Room.h"
#include "BinaryStream.h"

class RoomLookup
{
	friend BinaryStream &operator >>(BinaryStream &stream, RoomLookup &lookup);

	public:
		RoomLookup();

		std::vector<Room> &rooms();

	private:
		std::vector<Room> m_rooms;
};

#endif // ROOMLOOKUP_H
