#include "Projectile.h"

Projectile::Projectile(WorldPosition *position)
	: DrawableObject(position)
	, m_shouldBeDeleted(false)
{
}


void Projectile::onCollision(const WorldObject *other)
{
}

void Projectile::onSensorEnter(const b2Fixture *sensor, WorldObject *other)
{
}

void Projectile::onSensorLeave(const b2Fixture *sensor, WorldObject *other)
{
}

void Projectile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
}

void Projectile::update(const int delta)
{

}

void Projectile::deleteLater()
{
	m_shouldBeDeleted = true;
}
