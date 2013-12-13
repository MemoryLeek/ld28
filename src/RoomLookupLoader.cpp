#include "BinaryStream.h"
#include "RoomLookupLoader.h"

RoomLookupLoader::RoomLookupLoader(const std::string &fileName)
	: m_fileName(fileName)
{

}

RoomLookup *RoomLookupLoader::load()
{
	std::fstream file(m_fileName, std::ios::in | std::ios::binary);

	if(file.is_open())
	{
		RoomLookup *lookup = new RoomLookup();
		BinaryStream s(file);
		s >> *lookup;

		return lookup;
	}
	else
	{
		return 0;
	}
}
