#ifndef FLOATINGPANEL_H
#define FLOATINGPANEL_H

#include <SFML/System/String.hpp>
#include <SFML/Graphics/Font.hpp>

#include "UiElement.h"

class FloatingPanel : public UiElement
{
	public:
		FloatingPanel(const sf::String &text, sf::Window *window);

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		sf::Window *m_window;
		sf::String m_text;
		sf::Font m_font;
};

#endif // FLOATINGPANEL_H
