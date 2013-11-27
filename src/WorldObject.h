#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include "WorldPosition.h"

class WorldObject
{
	public:
		WorldObject(const WorldPosition *position, int width, int height);

		const WorldPosition *worldPosition() const;

		virtual void foo() = 0;

	private:
		const WorldPosition *m_worldPosition;
};

#endif // WORLDOBJECT_H
