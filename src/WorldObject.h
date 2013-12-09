#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include "WorldPosition.h"

class WorldObject
{
	public:
		WorldObject(WorldPosition *position, int width, int height);

		int width() const;
		int height() const;

		WorldPosition &worldPosition() const;

		virtual void foo() = 0;

	protected:
		int m_width;
		int m_height;

	private:
		WorldPosition *m_worldPosition;
};

#endif // WORLDOBJECT_H
