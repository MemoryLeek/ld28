#include <algorithm>
#include <set>
#include <vector>

#include "DereferencedEqual.h"
#include "DereferencedLess.h"
#include "Pathfinder.h"

Pathfinder::Pathfinder()
{
}

std::stack<b2Vec2> Pathfinder::find(const b2Vec2 &from, const b2Vec2 &to) const
{
	std::stack<b2Vec2> path;

	const PathNode targetNode(to.x / 32, to.y / 32, nullptr, nullptr);
	PathNode *originNode = new PathNode(from.x / 32, from.y / 32, nullptr, &targetNode);
	if(!isWalkable(originNode))
	{
		std::cout << "Origin node not walkable" << std::endl;
		delete originNode;
		return path;
	}

	// openList needs to be sorted by weight
	std::set<PathNode*, DereferencedLess<PathNode>> openList;
	std::vector<PathNode*> closedList;

	// Add the start node to the open list
	openList.insert(originNode);

	// Loop until we're at the target node (path found) or the open list is empty (no path to target)
	PathNode *current = *openList.begin();
	for(; current != *openList.end() && *current != targetNode; current = *openList.begin())
	{
		// Move the current node to the closed list
		openList.erase(current);
		closedList.push_back(current);

		// Check all 8 adjacent nodes
		for(int yOffset = -1; yOffset <= 1; yOffset++)
		{
			for(int xOffset = -1; xOffset <= 1; xOffset++)
			{
				PathNode node(current->x() + xOffset, current->y() + yOffset, current, &targetNode);

				if(node == *current)
				{
					continue;
				}

				// Skip if it isn't walkable or if it's already on the closed list
				if(!isWalkable(&node) || std::find_if(closedList.begin(), closedList.end(), DereferencedEqual<PathNode>(&node)) != closedList.end())
				{
					continue;
				}

				// If it isn't on the open list it should be added there
				if(std::find_if(openList.begin(), openList.end(), DereferencedEqual<PathNode>(&node)) == openList.end())
				{
					openList.insert(new PathNode(node));
				}
				else // Already on the open list, check if this path is better
				{
					PathNode *existingNode = *std::find_if(openList.begin(), openList.end(), DereferencedEqual<PathNode>(&node));

					if(node.weight() < existingNode->weight())
					{
						// Updating parent causes the weight to change, we need to remove and add to list to sort
						openList.erase(existingNode);
						existingNode->setParent(current);
						openList.insert(existingNode);
					}
				}
			}
		}
	}

	// If the open list still contains nodes we found our path, trace it back while converting it to pixel coords
	if(openList.size() > 0)
	{
		for(const PathNode *traceback = current; traceback != nullptr; traceback = traceback->parent())
		{
			// Add 16 to get coords to tile center
			path.push(b2Vec2(traceback->x() * 32 + 16,
							 traceback->y() * 32 + 16));
		}
	}

	// Cleanup
	for(PathNode *node : openList)
	{
		delete node;
	}

	for(PathNode *node : closedList)
	{
		delete node;
	}

	return path;
}

void Pathfinder::setWalkable(int x, int y, bool walkable)
{
	std::pair<int, int> position(x, y);
	m_walkables[position] = walkable;
}

bool Pathfinder::isWalkable(const PathNode *node) const
{
	std::pair<int, int> position(node->x(), node->y());
	return m_walkables.at(position);
}
