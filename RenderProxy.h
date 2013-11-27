#ifndef RENDERPROXY_H
#define RENDERPROXY_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class RenderProxy
{
	public:
		RenderProxy(sf::RenderTarget &subject, const sf::Vector2<int> &target);

		void draw(const sf::Drawable &drawable, sf::RenderStates states = sf::RenderStates::Default) const;

	private:
		sf::RenderTarget &m_subject;
		sf::Vector2<int> m_target;
};

#endif // RENDERPROXY_H
