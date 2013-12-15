#ifndef SPRITEBUNDLE_H
#define SPRITEBUNDLE_H

#include <vector>

#include "Sprite.h"
#include "BinaryStream.h"

class Scene;

class SpriteBundle
{
	friend BinaryStream &operator >>(BinaryStream &stream, SpriteBundle &bundle);

	public:
		SpriteBundle();

		void update(const int delta);
		void setImageIndex(const int index);

		const sf::Texture *currentImage() const;

		int spriteCount() const;
		int imageIndex() const;

	protected:
		std::vector<Sprite> m_sprites;

	private:
		int m_index;
};

#endif // SPRITEBUNDLE_H
