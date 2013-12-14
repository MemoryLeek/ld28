#ifndef MAP_H
#define MAP_H

#include <list>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class RoomObject;

class Map : public sf::Drawable
{
	public:
		Map();

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
		void addRoom(RoomObject *room);

	private:
		std::list<RoomObject *> m_rooms;
};

#endif // MAP_H
