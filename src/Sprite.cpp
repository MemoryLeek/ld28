#include <iostream>

#include "Sprite.h"
#include "StreamingOperators.h"

Sprite::Sprite()
	: m_delay(0)
	, m_index(0)
{

}

void Sprite::update(const int delta)
{
	const float f = (delta / 1000.0f) * (1000.0f / m_delay);
	const float c = m_index + f;
	const float i1 = c < m_frames.size() ? c : 0;
	const float i2 = i1 > -1 ? i1 : m_frames.size() - 1;

	m_index = i2;
}

const sf::Texture *Sprite::currentFrame() const
{
	return m_frames[m_index];
}

float Sprite::delay() const
{
	return m_delay;
}

int Sprite::frameCount() const
{
	return m_frames.size();
}

BinaryStream &operator >>(BinaryStream &stream, Sprite &sprite)
{
	stream >> sprite.m_delay;
	stream >> sprite.m_frames;

	return stream;
}
