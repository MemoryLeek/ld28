#include <iostream>

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
	Bot *bot = dynamic_cast<Bot *>(other);
	Player *player = dynamic_cast<Player *>(other);

	if(bot)
	{
		bot->doDamage(10);
	}
	else if(player)
	{
		player->doDamage(10);
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
