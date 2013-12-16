#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "TileObject.h"
#include "RoomObject.h"
#include "Room.h"

TileObject::TileObject(WorldPosition *position, const sf::Texture &texture)
	: DrawableObject(position)
	, m_texture(texture)
{

}

void TileObject::onCollision(WorldObject *other)
{
}

void TileObject::onSensorEnter(const b2Fixture *sensor, WorldObject *other)
{
}

void TileObject::onSensorLeave(const b2Fixture *sensor, WorldObject *other)
{
}

void TileObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	const WorldPosition &position = worldPosition();
	const b2Vec2 &vector = position.position();
	const b2Vec2 &size = position.size();
	const float rotation = position.rotation();

	sf::Sprite sprite(m_texture);
	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(vector.x, vector.y);
	sprite.setRotation(rotation);
	target.draw(sprite);
}

int TileObject::drawingOrder() const
{
	return -1;
}

bool TileObject::update(const int)
{
	return true;
}
