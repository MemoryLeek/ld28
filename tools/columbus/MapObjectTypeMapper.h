#ifndef MAPOBJECTTYPEMAPPER_H
#define MAPOBJECTTYPEMAPPER_H

#include <QHash>
#include <QString>

class MapObjectTypeMapper
{
	public:
		MapObjectTypeMapper();

		int map(const QString &typeName) const;

	private:
		QHash<QString, int> m_mappings;
};

#endif // MAPOBJECTTYPEMAPPER_H
