#ifndef TREASURECONTAINER_H
#define TREASURECONTAINER_H

#include "InteractableObject.h"

class TreasureContainer : public InteractableObject
{
	public:
		TreasureContainer(WorldPosition *worldPosition);

		void onInteraction() override;
		void update(const int delta) override;
};

#endif // TREASURECONTAINER_H
