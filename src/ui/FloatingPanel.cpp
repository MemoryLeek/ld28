#include <iostream>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Window.hpp>

#include "FloatingPanel.h"

FloatingPanel::FloatingPanel(const sf::String &text, sf::Window *window)
	: m_window(window)
	, m_text(text)
{
	m_font.loadFromFile("resources/mini_pixel-7.ttf");
}

void FloatingPanel::draw(sf::RenderTarget &target, sf::RenderStates) const
{
	const bool visible = isVisible();

	if(visible)
	{
		sf::Text text(m_text, m_font, 40);
		sf::Text textShadow(m_text, m_font, 40);
		textShadow.setColor(sf::Color(0, 0, 0));

		sf::Rect<float> f = text.getLocalBounds();
		sf::Vector2u windowSize = m_window->getSize();

		sf::Vector2f size(f.width + 30, f.height + 30);
		sf::RectangleShape panel;
		panel.setSize(size);
		panel.setPosition((windowSize.x - f.width) / 2, 50);
		panel.setOutlineColor(sf::Color(255, 255, 255));
		panel.setOutlineThickness(2);
		panel.setFillColor(sf::Color(255, 255, 255, 200));

		sf::RectangleShape panelShadow;
		panelShadow.setSize(size);
		panelShadow.setPosition((windowSize.x - f.width) / 2 + 2, 52);
		panelShadow.setFillColor(sf::Color(0, 0, 0, 0));
		panelShadow.setOutlineColor(sf::Color(0, 0, 0));
		panelShadow.setOutlineThickness(2);

		text.setPosition((windowSize.x - f.width) / 2 + 15, 47);
		textShadow.setPosition((windowSize.x - f.width) / 2 + 17, 49);

		target.draw(panelShadow);
		target.draw(panel);
		target.draw(textShadow);
		target.draw(text);
	}
}
