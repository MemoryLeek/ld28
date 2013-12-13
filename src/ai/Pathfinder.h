#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <set>
#include <stack>
#include <utility>

#include <Box2D/Common/b2Math.h>

#include "PathNode.h"

class Pathfinder
{
	public:
		Pathfinder();

		std::stack<b2Vec2> find(const b2Vec2 &from, const b2Vec2 &to) const;

		void setWalkable(int x, int y);

	private:
		bool isWalkable(const PathNode *node) const;

		std::set<std::pair<int, int>> m_walkables;
};

#endif // PATHFINDER_H
