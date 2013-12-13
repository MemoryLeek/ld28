#ifndef ROOMLOOKUP_H
#define ROOMLOOKUP_H

#include <list>

#include <SFML/Graphics/Drawable.hpp>

#include "RoomObject.h"
#include "BinaryStream.h"

class RoomLookup
{
	friend BinaryStream &operator >>(BinaryStream &stream, RoomLookup &lookup);

	public:
		RoomLookup();

		std::list<RoomObject> rooms() const;

	private:
		std::list<RoomObject> m_rooms;
};

#endif // ROOMLOOKUP_H
