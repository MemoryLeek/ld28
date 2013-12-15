#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "UiElement.h"

class Player;

class HealthBar : public UiElement
{
	public:
		HealthBar(const Player &player);

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		const Player &m_player;
};

#endif // HEALTHBAR_H
