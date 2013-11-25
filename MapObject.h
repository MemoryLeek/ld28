#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <SFML/Graphics/Rect.hpp>

class MapObject : public sf::Rect<int>
{
	public:
		MapObject();

		virtual void foo() = 0;
};

#endif // MAPOBJECT_H
