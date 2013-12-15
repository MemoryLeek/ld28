#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "HealthBar.h"
#include "Player.h"

HealthBar::HealthBar(const Player &player)
	: m_player(player)
{
}


void HealthBar::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if(isVisible())
	{
		const sf::Vector2<float> position(20, 20);
		const float remainingHealthPercentage = (float)m_player.remainingHealth() / m_player.maxHealth();

		sf::RectangleShape base(sf::Vector2<float>(102, 12));
		base.setPosition(position);
		base.setFillColor(sf::Color::White);

		sf::RectangleShape bar(sf::Vector2<float>(remainingHealthPercentage * 100, 10));
		bar.setPosition(position.x + 1, position.y + 1);
		bar.setFillColor(sf::Color::Red);

		target.draw(base);
		target.draw(bar);
	}
}
