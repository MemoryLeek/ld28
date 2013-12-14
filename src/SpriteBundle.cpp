#include "SpriteBundle.h"
#include "StreamingOperators.h"

SpriteBundle::SpriteBundle()
	: m_index(0)
{

}

void SpriteBundle::update(const int delta)
{
	Sprite &image = m_sprites[m_index];
	image.update(delta);
}

void SpriteBundle::setImageIndex(const int index)
{
	m_index = index;
}

const sf::Texture *SpriteBundle::currentImage() const
{
	const Sprite &image = m_sprites[m_index];
	const sf::Texture *frame = image.currentFrame();

	return frame;
}

int SpriteBundle::spriteCount() const
{
	return m_sprites.size();
}

int SpriteBundle::imageIndex() const
{
	return m_index;
}

BinaryStream &operator >>(BinaryStream &stream, SpriteBundle &bundle)
{
	stream >> bundle.m_sprites;

	return stream;
}
