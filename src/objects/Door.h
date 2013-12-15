#ifndef DOOR_H
#define DOOR_H

#include "InteractableObject.h"

class Door : public InteractableObject
{
	public:
		Door(WorldPosition *worldPosition, const Direction::Value direction, const sf::String &fileName);

		void onCollision(WorldObject *other) override;
		void onSensorEnter(const b2Fixture *sensor, WorldObject *other) override;
		void onSensorLeave(const b2Fixture *sensor, WorldObject *other) override;
		void onInteraction() override;
};

#endif // DOOR_H
