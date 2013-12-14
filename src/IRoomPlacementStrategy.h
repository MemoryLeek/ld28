#ifndef IROOMPLACEMENTSTRATEGY_H
#define IROOMPLACEMENTSTRATEGY_H

#include <Box2D/Common/b2Math.h>

#include "Room.h"

class IRoomPlacementStrategy
{
	public:
		virtual Coordinate position(const Room &first, const Room &second) const = 0;
};

#endif // IROOMPLACEMENTSTRATEGY_H
