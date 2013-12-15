#include <iostream>

#include "LaserPistol.h"
#include "PhysicsWorldPosition.h"
#include "Projectile.h"
#include "World.h"
#include "Map.h"

LaserPistol::LaserPistol(const WorldPosition &position, const b2Filter &filter, World &world, Map &map)
	: Weapon(position, filter, world, map)
{

}

void LaserPistol::fire()
{
	const b2Vec2 &origin = position().position();
	const float &angle = position().rotation();

	PhysicsWorldPosition *projectilePosition = m_world.createBox(origin, 16, 2, b2_dynamicBody, filter());
	projectilePosition->setRotation(angle);

	b2Body *projectileBody = projectilePosition->body();

	projectileBody->SetUserData(this);
	projectileBody->SetBullet(true);
	projectileBody->ApplyLinearImpulse(projectileBody->GetWorldVector(b2Vec2(.5f, 0)), projectileBody->GetWorldCenter(), true);

	Projectile *projectile = new Projectile(projectilePosition, m_map);

	m_map.addObject(projectile);
}
