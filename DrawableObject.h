#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include <SFML/Graphics/Sprite.hpp>

#include "MapObject.h"

class DrawableObject : public MapObject, public sf::Sprite
{
	public:
		DrawableObject(const sf::Texture &texture);

		void foo() override;
};

#endif // DRAWABLEOBJECT_H
