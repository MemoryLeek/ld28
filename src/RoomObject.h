#ifndef ROOMOBJECT_H
#define ROOMOBJECT_H

#include <list>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "DrawableObject.h"

class WorldObject;

class RoomObject : public DrawableObject
{
	public:
		RoomObject();

		void addObject(WorldObject *object);
		void done();

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
		void onCollision(WorldObject *other) override;
		void onSensorEnter(const b2Fixture *sensor, WorldObject *other) override;
		void onSensorLeave(const b2Fixture *sensor, WorldObject *other) override;

		bool update(const int delta) override;

	private:
		std::list<WorldObject *> m_objects;
};

#endif // ROOMOBJECT_H
