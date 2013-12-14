#ifndef SPRITE_H
#define SPRITE_H

#include <vector>

#include <SFML/Graphics/Texture.hpp>

#include "BinaryStream.h"
#include "ImageWrapper.h"

class Sprite
{
	friend BinaryStream &operator >>(BinaryStream &stream, Sprite &sprite);

	public:
		Sprite();

		void update(const int delta);

		const sf::Texture *currentFrame() const;

		float delay() const;
		int frameCount() const;

	private:
		std::vector<ImageWrapper> m_frames;

		float m_delay;
		float m_index;
};

#endif // SPRITE_H
