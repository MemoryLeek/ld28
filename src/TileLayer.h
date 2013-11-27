#ifndef TILELAYER_H
#define TILELAYER_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Drawable.hpp>

class TileLayer : public sf::Drawable
{
	public:
		TileLayer(const sf::Texture *texture, const sf::Rect<int> &rect);

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		const sf::Texture *m_texture;
		const sf::Rect<int> m_rect;
};

#endif // TILELAYER_H
