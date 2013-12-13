#ifndef TILEOBJECT_H
#define TILEOBJECT_H

#include <QImage>
#include <QPainter>

class Tile
{
	public:
		Tile();
		Tile(const int width, const int height);

		~Tile();

		QPainter *painter();

		bool collidable() const;
		void setCollidable(const bool collidable);

	private:
		friend QDataStream &operator <<(QDataStream &stream, const Tile &tile);

		QImage m_texture;
		QPainter *m_painter;

		bool m_collidable;
};

#endif // TILEOBJECT_H
