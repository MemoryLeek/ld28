#include <iostream>

#include "Player.h"
#include "TreasureContainer.h"

TreasureContainer::TreasureContainer(WorldPosition *worldPosition)
	: InteractableObject("resources/hp.spb", worldPosition)
	, m_empty(false)
{

}

void TreasureContainer::onInteraction(Player &player)
{
	if(!m_empty)
	{
		player.giveHealth(100);
		m_empty = true;
		setImageIndex(1);
	}
}

bool TreasureContainer::update(const int delta)
{
	return true;
}
