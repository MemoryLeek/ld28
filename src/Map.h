#ifndef MAP_H
#define MAP_H

#include <list>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class RoomObject;
class WorldObject;
class DrawableObject;

class Map : public sf::Drawable
{
	public:
		Map();

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
		void update(const int delta);

		void addObject(DrawableObject *worldObject);
		void removeObject(DrawableObject *worldObject);

	private:
		std::list<DrawableObject *> m_drawables;
		std::list<WorldObject *> m_objects;
};

#endif // MAP_H
