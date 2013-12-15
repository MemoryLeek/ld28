#include <iostream>

#include "LaserPistol.h"
#include "PhysicsWorldPosition.h"
#include "Projectile.h"
#include "World.h"
#include "Map.h"

LaserPistol::LaserPistol(const WorldPosition &position, World &world, Map &map)
	: Weapon(position, world, map)
{

}

void LaserPistol::fire()
{
	const b2Vec2 &origin = position().position();
	const float &angle = position().rotation();

	b2Filter projectileFilter;
	projectileFilter.categoryBits = World::PlayerProjectile;
	projectileFilter.maskBits = 0xFFFF ^ World::Player;

	PhysicsWorldPosition *projectilePosition = m_world.createBox(origin, 16, 2, b2_dynamicBody, projectileFilter);
	projectilePosition->setRotation(angle);

	b2Body *projectileBody = projectilePosition->body();

	projectileBody->SetUserData(this);
	projectileBody->SetBullet(true);
	projectileBody->ApplyLinearImpulse(projectileBody->GetWorldVector(b2Vec2(.5f, 0)), projectileBody->GetWorldCenter(), true);

	Projectile *projectile = new Projectile(projectilePosition, m_map);

	m_map.addObject(projectile);
}
