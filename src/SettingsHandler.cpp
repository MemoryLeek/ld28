#include <fstream>

#include "SettingsHandler.h"
#include "Settings.h"

SettingsHandler::SettingsHandler(const sf::String &fileName)
{
	Settings settings;
	std::ifstream stream(fileName, std::ifstream::binary | std::ios_base::in);
}

InputMapping &SettingsHandler::mapping()
{
	return m_mapping;
}
