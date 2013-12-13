#ifndef ROOMLOOKUPLOADER_H
#define ROOMLOOKUPLOADER_H

#include <list>

#include "RoomLookup.h"

class RoomLookupLoader
{
	public:
		RoomLookupLoader(const std::string &fileName);

		RoomLookup *load();

	private:
		std::string m_fileName;
		std::list<RoomLookup> m_rooms;
};

#endif // ROOMLOOKUPLOADER_H
