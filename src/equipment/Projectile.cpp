#include <iostream>

#include <SFML/Graphics/RectangleShape.hpp>

#include "Player.h"

#include "Projectile.h"
#include "Map.h"

#include "ai/Bot.h"

Projectile::Projectile(WorldPosition *position, Map &map)
	: DrawableObject(position)
	, m_map(map)
	, m_shouldBeDeleted(false)
{
}

void Projectile::onCollision(WorldObject *other)
{
	Damagable *damagable = dynamic_cast<Damagable *>(other);

	if(damagable)
	{
		damagable->doDamage(10);
	}
}

void Projectile::onSensorEnter(const b2Fixture *sensor, WorldObject *other)
{
}

void Projectile::onSensorLeave(const b2Fixture *sensor, WorldObject *other)
{
}

void Projectile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	const WorldPosition &position = worldPosition();
	const b2Vec2 &vector = position.position();
	const b2Vec2 &size = position.size();
	const float rotation = position.rotation();

	sf::Color color(255, 0, 0, 200);
	sf::RectangleShape shape;
	shape.setOrigin(size.x / 2, size.y / 2);
	shape.setPosition(vector.x, vector.y);
	shape.setSize(sf::Vector2f(size.x, size.y));
	shape.setFillColor(color);
	shape.setOutlineColor(color);
	shape.setOutlineThickness(2);
	shape.setRotation(rotation);

	target.draw(shape, states);
}

bool Projectile::update(const int delta)
{
	if(m_shouldBeDeleted)
	{
		m_map.removeObject(this);

		return false;
	}

	return true;
}

void Projectile::deleteLater()
{
	m_shouldBeDeleted = true;
}
