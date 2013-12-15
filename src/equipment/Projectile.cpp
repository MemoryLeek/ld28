#include "Projectile.h"

Projectile::Projectile(WorldPosition *position, int width, int height)
	: DrawableObject(position, width, height)
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

void Projectile::deleteLater()
{
	m_shouldBeDeleted = true;
}
