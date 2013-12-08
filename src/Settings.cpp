#include "Settings.h"
#include "StreamingOperators.h"

InputMapping &Settings::mapping()
{
	return m_mapping;
}

BinaryStream &operator >>(BinaryStream &stream, Settings &settings)
{
	stream >> settings.m_mapping;

	return stream;
}

BinaryStream &operator <<(BinaryStream &stream, const Settings &settings)
{
	stream << settings.m_mapping;

	return stream;
}
