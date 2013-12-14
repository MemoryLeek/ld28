#ifndef ROOMLOADER_H
#define ROOMLOADER_H

#include <QString>

#include "RoomObject.h"

class IDirectionSelectorStrategy;

class RoomLoader
{
	public:
		RoomLoader();

		Room *load(const QString &path) const;

	private:
		QList<IDirectionSelectorStrategy *> m_directionSelectorStrategies;
};

#endif // ROOMLOADER_H
