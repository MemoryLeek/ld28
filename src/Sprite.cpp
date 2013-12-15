#include <iostream>

#include "Sprite.h"
#include "StreamingOperators.h"

Sprite::Sprite()
	: m_delay(0)
	, m_index(0)
	, m_loops(0)
{

}

void Sprite::update(const int delta)
{
	const float f = (delta / 1000.0f) * (1000.0f / m_delay);
	const float candidate = m_index + f;
	const float count = m_frames.size();

	if(candidate > count)
	{
		if(m_loops <= 0)
		{
			m_index = 0;
		}
	}
	else
	{
		m_index = candidate;
	}
}

const sf::Texture *Sprite::currentFrame() const
{
	return m_frames[m_index];
}

int Sprite::delay() const
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
	stream >> sprite.m_loops;

	return stream;
}
