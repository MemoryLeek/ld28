#include <iostream>

#include <SFML/Graphics/RenderTarget.hpp>

#include "TileObject.h"
#include "RenderProxy.h"

TileObject::TileObject(int x, int y, int width, int height)
	: DrawableObject(x, y, width, height)
	, m_collidable(false)
{
}

void TileObject::addLayer(const TileLayer &layer)
{
	m_layers.push_back(layer);
}

bool TileObject::isCollidable() const
{
	return m_collidable;
}

void TileObject::setCollidable(bool collidable)
{
	m_collidable = collidable;
}

void TileObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	const sf::Vector2<int> vector(left, top);

	for(const TileLayer &layer : m_layers)
	{
		RenderProxy proxy(target, vector);
		proxy.draw(layer, states);
	}
}
