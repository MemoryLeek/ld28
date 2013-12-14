#ifndef ROOMLOOKUP_H
#define ROOMLOOKUP_H

#include <QList>
#include <QDataStream>

class Room;

class RoomLookup
{
	public:
		RoomLookup();

		void addRoom(const Room &room);

	private:
		friend QDataStream &operator <<(QDataStream &stream, const RoomLookup &lookup);

		QList<Room> m_rooms;
};

#endif // ROOMLOOKUP_H
