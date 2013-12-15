#ifndef DOOR_H
#define DOOR_H

#include "AnimatedObject.h"

class Door : public AnimatedObject
{
	public:
		Door(WorldPosition *worldPosition);

		void onCollision(WorldObject *other) override;
		void onSensorEnter(const b2Fixture *sensor, WorldObject *other) override;
		void onSensorLeave(const b2Fixture *sensor, WorldObject *other) override;
};

#endif // DOOR_H
