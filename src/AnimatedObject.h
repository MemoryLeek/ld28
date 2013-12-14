#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H

#include <SFML/System/String.hpp>

#include "DrawableObject.h"

class SpriteBundle;

class AnimatedObject : public DrawableObject
{
	public:
		AnimatedObject(const sf::String &fileName, WorldPosition *worldPosition, int width, int height);

		void setImageIndex(const int index);
		void update(const int delta);
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		SpriteBundle *m_spriteBundle;
};

#endif // ANIMATEDOBJECT_H
