#include <iostream>

#include "TreasureContainer.h"

TreasureContainer::TreasureContainer(WorldPosition *worldPosition)
	: InteractableObject(worldPosition)
{

}

void TreasureContainer::onInteraction()
{
	std::cout << "The player is interacting with the treasure, huzzah!" << std::endl;
}

bool TreasureContainer::update(const int delta)
{
	return true;
}
