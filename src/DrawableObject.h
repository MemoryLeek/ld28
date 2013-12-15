#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include <SFML/Graphics/Drawable.hpp>

#include "WorldObject.h"

class DrawableObject : public WorldObject, public sf::Drawable
{
	public:
		DrawableObject(WorldPosition *position);
		virtual ~DrawableObject();

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override = 0;
};

#endif // DRAWABLEOBJECT_H
