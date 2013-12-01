#ifndef SETTINGSHANDLER_H
#define SETTINGSHANDLER_H

#include <SFML/System/String.hpp>

#include "InputMapping.h"

class SettingsHandler
{
	public:
		SettingsHandler(const sf::String &fileName);

		InputMapping &mapping();

	private:
		InputMapping m_mapping;
};

#endif // SETTINGSHANDLER_H
