#include <QDebug>

#include "MutableSprite.h"

MutableSprite::MutableSprite()
	: m_index(0)
	, m_delay(0)
{

}

void MutableSprite::addFrame(const QImage image)
{
	m_frames << image;
}

void MutableSprite::setDelay(const int delay)
{
	m_delay = delay;
}

void MutableSprite::setLoops(const int loops)
{
	m_loops = loops;
}

bool MutableSprite::isValid() const
{
	return !m_frames.isEmpty();
}

QDataStream &operator <<(QDataStream &stream, const MutableSprite &sprite)
{
	stream << sprite.m_delay;
	stream << sprite.m_frames;
	stream << sprite.m_loops;

	return stream;
}
