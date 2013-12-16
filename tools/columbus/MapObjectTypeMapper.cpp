#include "MapObjectTypeMapper.h"

MapObjectTypeMapper::MapObjectTypeMapper()
{
	m_mappings =
	{
		{ "door", 0 },
		{ "key", 1 },
		{ "spawn", 2 }
	};
}

int MapObjectTypeMapper::map(const QString &typeName) const
{
	return m_mappings.value(typeName, -1);
}
