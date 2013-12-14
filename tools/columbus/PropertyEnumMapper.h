#ifndef PROPERTYENUMMAPPER_H
#define PROPERTYENUMMAPPER_H

#include <QString>

#include <tiled/map.h>

template<class T>
class PropertyEnumMapper
{
	public:
		static T map(Tiled::Map *map, const QString &propertyName)
		{
			const QString &stringValue = map->property(propertyName);
			const T &enumValue = (T)stringValue.toInt();

			return enumValue;
		}
};

#endif // PROPERTYENUMMAPPER_H
