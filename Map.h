#ifndef MAP_H
#define MAP_H

#include <list>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class MapObject;

class Map : public sf::Drawable
{
	public:
		Map();

		std::list<const MapObject *> objects() const;
		void addObject(const MapObject *object);

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		std::list<const MapObject *> m_objects;
};

#endif // MAP_H
