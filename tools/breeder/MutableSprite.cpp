#include <QDebug>

#include "MutableSprite.h"

MutableSprite::MutableSprite()
	: m_delay(0)
	, m_index(0)
{

}

void MutableSprite::addFrame(const QImage image)
{
	m_frames << image;
}

void MutableSprite::setDelay(const float delay)
{
	m_delay = delay;
}

bool MutableSprite::isValid() const
{
	return !m_frames.isEmpty();
}

QDataStream &operator <<(QDataStream &stream, const MutableSprite &sprite)
{
	stream << sprite.m_delay;
	stream << sprite.m_frames;

	return stream;
}
