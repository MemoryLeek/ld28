#include "SpriteLoader.h"
#include "SpriteBundle.h"
#include "BinaryStream.h"

SpriteBundle *SpriteLoader::load(const sf::String &fileName)
{
	std::fstream file(fileName, std::ios::in | std::ios::binary);

	if(file.is_open())
	{
		SpriteBundle *bundle = new SpriteBundle();
		BinaryStream stream(file);
		stream >> *bundle;

		return bundle;
	}
	else
	{
		return 0;
	}
}
