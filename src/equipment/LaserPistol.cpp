#include <iostream>

#include "LaserPistol.h"
#include "PhysicsWorldPosition.h"
#include "Projectile.h"
#include "World.h"

LaserPistol::LaserPistol(const WorldPosition &position, World &world)
	: Weapon(position, world)
{
}

void LaserPistol::fire()
{
	std::cout << "LaserPistol::fire()" << std::endl;

	const b2Vec2 &origin = position().position();
	const float &angle = position().rotation();

	b2Filter projectileFilter;
	projectileFilter.categoryBits = World::PlayerProjectile;
	projectileFilter.maskBits = 0xFFFF ^ World::Player;

	PhysicsWorldPosition *projectilePosition = world().createBox(origin, 16, 2, b2_dynamicBody, projectileFilter);
	projectilePosition->setRotation(angle);

	b2Body *projectileBody = projectilePosition->body();

	projectileBody->SetUserData(this);
	projectileBody->SetBullet(true);
	projectileBody->ApplyLinearImpulse(projectileBody->GetWorldVector(b2Vec2(.5f, 0)), projectileBody->GetWorldCenter(), true);

	new Projectile(projectilePosition, 16, 2);
}
