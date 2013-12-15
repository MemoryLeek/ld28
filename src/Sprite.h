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

		int delay() const;
		int frameCount() const;

	private:
		std::vector<ImageWrapper> m_frames;

		float m_index;

		int m_delay;
		int m_loops;
};

#endif // SPRITE_H
