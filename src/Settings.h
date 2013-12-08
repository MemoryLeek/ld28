#ifndef SETTINGS_H
#define SETTINGS_H

#include <fstream>
#include <list>

#include "KeyMapping.h"
#include "InputMapping.h"
#include "BinaryStream.h"

class Settings
{
	public:
		InputMapping &mapping();

	private:
		friend BinaryStream &operator >>(BinaryStream &stream, Settings &settings);
		friend BinaryStream &operator <<(BinaryStream &stream, const Settings &settings);

		InputMapping m_mapping;
};

#endif // SETTINGS_H
