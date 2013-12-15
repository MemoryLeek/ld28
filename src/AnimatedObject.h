#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H

#include <SFML/System/String.hpp>

#include "DrawableObject.h"
#include "Direction.h"

class SpriteBundle;

class AnimatedObject : public DrawableObject
{
	public:
		AnimatedObject(const sf::String &fileName, WorldPosition *worldPosition);

		void setImageIndex(const int index);
		void update(const int delta);
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	protected:
		virtual sf::String getFilename(const sf::String &fileName, const Direction::Value direction);

	private:
		SpriteBundle *m_spriteBundle;
};

#endif // ANIMATEDOBJECT_H
