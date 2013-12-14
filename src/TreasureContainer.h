#ifndef TREASURECONTAINER_H
#define TREASURECONTAINER_H

#include "DrawableObject.h"

class TreasureContainer : public DrawableObject
{
	public:
		TreasureContainer(WorldPosition *position);

		void onCollision(const WorldObject *other) override;
		void onSensorEnter(const b2Fixture *sensor, WorldObject *other) override;
		void onSensorLeave(const b2Fixture *sensor, WorldObject *other) override;

		void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif // TREASURECONTAINER_H
