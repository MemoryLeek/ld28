#ifndef COLUMBUS_MAPOBJECT_H
#define COLUMBUS_MAPOBJECT_H

#include <QDataStream>

class MapObject
{
	friend QDataStream &operator <<(QDataStream &stream, const MapObject &object);

	public:
		MapObject();
		MapObject(const int id, const int direction);

	private:
		int m_id;
		int m_direction;
};

#endif // COLUMBUS_MAPOBJECT_H
