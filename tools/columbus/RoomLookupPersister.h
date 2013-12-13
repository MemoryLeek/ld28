#ifndef ROOMLOOKUPPERSISTER_H
#define ROOMLOOKUPPERSISTER_H

#include "RoomLookup.h"

class RoomLookupPersister
{
	public:
		RoomLookupPersister(const QString &fileName);

		void persist(RoomLookup lookup);

	private:
		QString m_fileName;
};

#endif // ROOMLOOKUPPERSISTER_H
