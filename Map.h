#ifndef MAP_H
#define MAP_H

#include <list>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class WorldObject;

class Map : public sf::Drawable
{
	public:
		Map();

		std::list<const WorldObject *> objects() const;
		void addObject(const WorldObject *object);

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		std::list<const WorldObject *> m_objects;
};

#endif // MAP_H
