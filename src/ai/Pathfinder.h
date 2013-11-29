#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stack>

#include <Box2D/Common/b2Math.h>

class Pathfinder
{
	public:
		Pathfinder();

		std::stack<b2Vec2> find(const b2Vec2 &from, const b2Vec2 &to) const;
};

#endif // PATHFINDER_H
