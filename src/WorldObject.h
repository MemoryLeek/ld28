#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <Box2D/Dynamics/b2Fixture.h>

#include "WorldPosition.h"

class WorldObject
{
	public:
		WorldObject();
		WorldObject(WorldPosition *position, int width, int height);

		int width() const;
		int height() const;

		WorldPosition &worldPosition() const;

		virtual void onCollision(const WorldObject *other) = 0;
		virtual void onSensorEnter(const b2Fixture *sensor, WorldObject *other) = 0;
		virtual void onSensorLeave(const b2Fixture *sensor, WorldObject *other) = 0;

	protected:
		int m_width;
		int m_height;

	private:
		WorldPosition *m_worldPosition;
};

#endif // WORLDOBJECT_H
