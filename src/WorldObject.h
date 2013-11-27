#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include "WorldPosition.h"

class WorldObject
{
	public:
		WorldObject(WorldPosition *position, int width, int height);

		WorldPosition *worldPosition() const;

		virtual void foo() = 0;

	private:
		WorldPosition *m_worldPosition;
};

#endif // WORLDOBJECT_H
