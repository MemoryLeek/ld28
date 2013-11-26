#include <SFML/Graphics/RenderTarget.hpp>

#include "TileObject.h"

TileObject::TileObject(int x, int y, int width, int height)
	: DrawableObject(x, y, width, height)
{
}

void TileObject::setLayer(int z, const sf::Sprite &sprite)
{
	m_layers[z] = sprite;
}

void TileObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for(const std::pair<const int, sf::Sprite> &sprite : m_layers)
	{
		target.draw(sprite.second, states);
	}
}
