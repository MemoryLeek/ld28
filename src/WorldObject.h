#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <Box2D/Dynamics/b2Fixture.h>

#include "WorldPosition.h"

class Map;

class WorldObject
{
	public:
		WorldObject();
		WorldObject(WorldPosition *position);

		virtual ~WorldObject();

		WorldPosition &worldPosition() const;

		virtual void onCollision(WorldObject *other) = 0;
		virtual void onSensorEnter(const b2Fixture *sensor, WorldObject *other) = 0;
		virtual void onSensorLeave(const b2Fixture *sensor, WorldObject *other) = 0;

		virtual bool update(const int delta) = 0;

	private:
		WorldPosition *m_worldPosition;
};

#endif // WORLDOBJECT_H
