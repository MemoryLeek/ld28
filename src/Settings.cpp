#include "Settings.h"
#include "StreamingOperators.h"

Settings::Settings()
{

}

std::ifstream &operator >>(std::ifstream &stream, Settings &settings)
{
//	stream >> settings.m_mappings;

	return stream;
}

std::ofstream &operator <<(std::ofstream &stream, Settings &settings)
{
//	stream << settings.m_mappings;

	return stream;
}
