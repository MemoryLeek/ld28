#include <iostream>

#include "ImageWrapper.h"

ImageWrapper::operator const sf::Texture *() const
{
	return &m_texture;
}

BinaryStream &operator >>(BinaryStream &stream, ImageWrapper &wrapper)
{
	unsigned int size = 0;

	stream >> size;

	char *data = stream.read(size);

	sf::Texture &texture = wrapper.m_texture;
	texture.loadFromMemory(data, size);

	return stream;
}
