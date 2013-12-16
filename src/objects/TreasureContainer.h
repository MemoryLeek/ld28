#ifndef TREASURECONTAINER_H
#define TREASURECONTAINER_H

#include "InteractableObject.h"

class TreasureContainer : public InteractableObject
{
	public:
		TreasureContainer(WorldPosition *worldPosition);

		void onInteraction(Player &player) override;
		bool update(const int delta) override;

	private:
		bool m_empty;
};

#endif // TREASURECONTAINER_H
