#ifndef TILEOBJECT_H
#define TILEOBJECT_H

#include <QImage>
#include <QPainter>

class TileObject
{
	friend QDataStream &operator <<(QDataStream &stream, const TileObject &tile);

	public:
		TileObject();
		TileObject(const int width, const int height);

		~TileObject();

		QPainter *painter();

		bool collidable() const;
		void setCollidable(const bool collidable);

	private:
		QImage m_texture;
		QPainter *m_painter;

		bool m_collidable;
};

#endif // TILEOBJECT_H
