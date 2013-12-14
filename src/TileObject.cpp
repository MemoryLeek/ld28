#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "TileObject.h"
#include "RoomObject.h"
#include "Room.h"

TileObject::TileObject(WorldPosition *position, const sf::Texture &texture)
	: DrawableObject(position, TILE_SIZE, TILE_SIZE)
	, m_texture(texture)
{

}

void TileObject::onCollision(const WorldObject *other)
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
	const WorldPosition &wp = worldPosition();
	const b2Vec2 &p = wp.position();
	const sf::Vertex vertices[]
	{
		sf::Vertex
		{
			sf::Vector2f(p.x, p.y),
			sf::Vector2f(0, 0)
		},
		sf::Vertex
		{
			sf::Vector2f(p.x, p.y + TILE_SIZE),
			sf::Vector2f(0, TILE_SIZE)
		},
		sf::Vertex
		{
			sf::Vector2f(p.x + TILE_SIZE, p.y + TILE_SIZE),
			sf::Vector2f(TILE_SIZE, TILE_SIZE)
		},
		sf::Vertex
		{
			sf::Vector2f(p.x + TILE_SIZE, p.y),
			sf::Vector2f(TILE_SIZE, 0)
		}
	};

	sf::Transform transform;
	transform.translate(-TILE_SIZE / 2, -TILE_SIZE / 2);

	states.texture = &m_texture;
	states.transform = transform;

	target.draw(vertices, 4, sf::Quads, states);
}
