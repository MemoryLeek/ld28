#ifndef SETTINGSPROVIDER_H
#define SETTINGSPROVIDER_H

#include <SFML/System/String.hpp>

#include "ISettingsProvider.h"

class SettingsProvider : public ISettingsProvider
{
	public:
		SettingsProvider(const sf::String &fileName, ISettingsProvider *fallbackProvider);

		Settings load() override;
		void save(const Settings &settings) override;

	private:
		sf::String m_fileName;
		ISettingsProvider *m_fallbackProvider;
};

#endif // SETTINGSPROVIDER_H
