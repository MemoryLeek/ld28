#ifndef RENDERPROXY_H
#define RENDERPROXY_H

#include <Box2D/Common/b2Math.h>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class RenderProxy
{
	public:
		RenderProxy(sf::RenderTarget &subject, const b2Vec2 &target);

		void draw(const sf::Drawable &drawable, sf::RenderStates states = sf::RenderStates::Default) const;

	private:
		sf::RenderTarget &m_subject;
		b2Vec2 m_target;
};

#endif // RENDERPROXY_H
