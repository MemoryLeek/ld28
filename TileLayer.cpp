#include <SFML/Graphics/RenderTarget.hpp>

#include "TileLayer.h"

TileLayer::TileLayer(const sf::Texture *texture, const sf::Rect<int> &rect)
	: m_texture(texture)
	, m_rect(rect)
{

}

void TileLayer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	sf::Vertex vertices[]
	{
		sf::Vertex
		{
			sf::Vector2f(0, 0),
			sf::Vector2f(m_rect.left, m_rect.top)
		},
		sf::Vertex
		{
			sf::Vector2f(0, m_rect.height),
			sf::Vector2f(m_rect.left, m_rect.top + m_rect.height)
		},
		sf::Vertex
		{
			sf::Vector2f(m_rect.width, m_rect.height),
			sf::Vector2f(m_rect.left + m_rect.width, m_rect.top + m_rect.height)
		},
		sf::Vertex
		{
			sf::Vector2f(m_rect.width, 0),
			sf::Vector2f(m_rect.left + m_rect.width, m_rect.top)
		}
	};

	states.texture = m_texture;

	target.draw(vertices, 4, sf::Quads, states);
}
