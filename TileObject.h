#ifndef TILEOBJECT_H
#define TILEOBJECT_H

#include <map>

#include <SFML/Graphics/Sprite.hpp>

#include "DrawableObject.h"

class TileObject : public DrawableObject
{
	public:
		TileObject(int x, int y, int width, int height);

		void setLayer(int z, const sf::Sprite &sprite);

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		std::map<const int, sf::Sprite> m_layers;
};

#endif // TILEOBJECT_H
