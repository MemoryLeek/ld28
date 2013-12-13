#ifndef ROOMLOADER_H
#define ROOMLOADER_H

#include <QString>

#include "RoomObject.h"

class RoomLoader
{
	public:
		RoomLoader();

		RoomObject *load(const QString &path) const;
};

#endif // ROOMLOADER_H
