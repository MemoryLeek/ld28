#ifndef TILEOBJECT_H
#define TILEOBJECT_H

#include <QImage>
#include <QPainter>

#include "MapObject.h"

class TileObject
{
	friend QDataStream &operator <<(QDataStream &stream, const TileObject &tile);

	public:
		TileObject();
		TileObject(const int width, const int height);

		~TileObject();

		QPainter *painter();

		void setCollidable(const bool collidable);
		void setHasContent(const bool hasContent);
		void setMapObject(const MapObject &mapObject);

	private:
		QImage m_texture;
		QPainter *m_painter;

		bool m_collidable;
		bool m_hasContent;

		MapObject m_mapObject;
};

#endif // TILEOBJECT_H
