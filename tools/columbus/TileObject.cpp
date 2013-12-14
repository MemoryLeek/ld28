#include <QBuffer>
#include <QDebug>

#include "TileObject.h"

TileObject::TileObject()
	: m_painter(0)
	, m_collidable(false)
{

}

TileObject::TileObject(const int width, const int height)
	: m_texture(width, height, QImage::Format_ARGB32)
	, m_collidable(false)
{
	m_painter = new QPainter(&m_texture);
}

TileObject::~TileObject()
{
	if(m_painter)
	{
		m_painter->end();
	}

	delete m_painter;
}

QPainter *TileObject::painter()
{
	return m_painter;
}

bool TileObject::collidable() const
{
	return m_collidable;
}

void TileObject::setCollidable(bool collidable)
{
	m_collidable = collidable;
}

QDataStream &operator <<(QDataStream &stream, const TileObject &tile)
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
