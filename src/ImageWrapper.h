#ifndef IMAGEWRAPPER_H
#define IMAGEWRAPPER_H

#include <SFML/Graphics/Texture.hpp>

#include "BinaryStream.h"

class ImageWrapper
{
	friend BinaryStream &operator >>(BinaryStream &stream, ImageWrapper &wrapper);

	public:
		operator const sf::Texture *() const;

	private:
		sf::Texture m_texture;
};

#endif // IMAGEWRAPPER_H
