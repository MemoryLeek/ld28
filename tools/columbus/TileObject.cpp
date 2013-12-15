#include <QBuffer>
#include <QDebug>

#include "TileObject.h"

TileObject::TileObject()
	: m_painter(0)
	, m_collidable(false)
	, m_hasContent(false)
	, m_mapObject(-1)
{

}

TileObject::TileObject(const int width, const int height)
	: m_texture(width, height, QImage::Format_ARGB32)
	, m_collidable(false)
	, m_hasContent(false)
	, m_mapObject(-1)
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

void TileObject::setCollidable(bool collidable)
{
	m_collidable = collidable;
}

void TileObject::setHasContent(const bool hasContent)
{
	m_hasContent = hasContent;
}

void TileObject::setMapObject(const int mapObject)
{
	m_mapObject = mapObject;
}

QDataStream &operator <<(QDataStream &stream, const TileObject &tile)
{
	QBuffer buffer;
	buffer.open(QIODevice::WriteOnly);

	QImage texture = tile.m_texture;
	texture.save(&buffer, "PNG");

	QByteArray array = buffer.data();

	stream << tile.m_collidable;
	stream << tile.m_hasContent;
	stream << tile.m_mapObject;
	stream << array;

	return stream;
}
