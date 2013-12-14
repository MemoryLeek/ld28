#ifndef TILEOBJECT_H
#define TILEOBJECT_H

#include <SFML/Graphics/Texture.hpp>

#include "DrawableObject.h"

class TileObject : public DrawableObject
{
	public:
		TileObject(WorldPosition *position, const sf::Texture &texture);

		void onCollision(const WorldObject *other) override;
		void onSensorEnter(const b2Fixture *sensor, WorldObject *other) override;
		void onSensorLeave(const b2Fixture *sensor, WorldObject *other) override;

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		sf::Texture m_texture;
};

#endif // TILEOBJECT_H
