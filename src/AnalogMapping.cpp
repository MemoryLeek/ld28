#include "AnalogMapping.h"

AnalogMapping::AnalogMapping()
{

}

void AnalogMapping::invokeAbsolute(const float x, const float y)
{
	if(m_absolute)
	{
		m_absolute(x, y);
	}
}

void AnalogMapping::invokeRelative(const float x, const float y)
{
	if(m_relative)
	{
		m_relative(x, y);
	}
}
