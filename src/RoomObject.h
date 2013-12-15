#ifndef ROOMOBJECT_H
#define ROOMOBJECT_H

#include <list>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class WorldObject;

class RoomObject : public sf::Drawable
{
	public:
		std::list<const WorldObject *> objects() const;

		void addObject(const WorldObject *object);
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		std::list<const WorldObject *> m_objects;
};

#endif // ROOMOBJECT_H
