#include <QBuffer>
#include <QDebug>

#include "TileObject.h"

Tile::Tile()
	: m_painter(0)
	, m_collidable(false)
{

}

Tile::Tile(const int width, const int height)
	: m_texture(width, height, QImage::Format_ARGB32)
	, m_collidable(false)
{
	m_painter = new QPainter(&m_texture);
}

Tile::~Tile()
{
	if(m_painter)
	{
		m_painter->end();
	}

	delete m_painter;
}

QPainter *Tile::painter()
{
	return m_painter;
}

bool Tile::collidable() const
{
	return m_collidable;
}

void Tile::setCollidable(bool collidable)
{
	m_collidable = collidable;
}

QDataStream &operator <<(QDataStream &stream, const Tile &tile)
{
	QBuffer buffer;
	buffer.open(QIODevice::WriteOnly);

	QImage texture = tile.m_texture;
	texture.save(&buffer, "PNG");

	QByteArray array = buffer.data();

	stream << tile.m_collidable;
	stream << array;

	return stream;
}
