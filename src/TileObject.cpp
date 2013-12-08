#include <iostream>

#include <SFML/Graphics/RenderTarget.hpp>

#include "TileObject.h"
#include "RenderProxy.h"

TileObject::TileObject(WorldPosition *position, int width, int height)
	: DrawableObject(position, width, height)
{
}

void TileObject::addLayer(const TileLayer &layer)
{
	m_layers.push_back(layer);
}

void TileObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	const WorldPosition *position = worldPosition();
	b2Vec2 vector = position->position();
	vector -= b2Vec2(width() / 2, height() / 2);

	for(const TileLayer &layer : m_layers)
	{
		RenderProxy proxy(target, vector);
		proxy.draw(layer, states);
	}
}
