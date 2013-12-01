#ifndef SETTINGS_H
#define SETTINGS_H

#include <fstream>
#include <list>

#include "KeyMapping.h"

class Settings
{
	public:
		Settings();

	private:
		friend std::ifstream &operator >>(std::ifstream &stream, Settings &settings);
		friend std::ofstream &operator <<(std::ofstream &stream, Settings &settings);

//		std::list<KeyMapping> m_mappings;
};

#endif // SETTINGS_H
