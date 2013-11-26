#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <SFML/Graphics/Rect.hpp>

class WorldObject : public sf::Rect<int>
{
	public:
		WorldObject(int x, int y, int width, int height);

		virtual void foo() = 0;
};

#endif // WORLDOBJECT_H
