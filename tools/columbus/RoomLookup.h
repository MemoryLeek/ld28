#ifndef ROOMLOOKUP_H
#define ROOMLOOKUP_H

#include <QList>
#include <QDataStream>

class RoomObject;

class RoomLookup
{
	public:
		RoomLookup();

		void addRoom(const RoomObject &room);

	private:
		friend QDataStream &operator <<(QDataStream &stream, const RoomLookup &lookup);

		QList<RoomObject> m_rooms;
};

#endif // ROOMLOOKUP_H
