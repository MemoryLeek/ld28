#include <iostream>

#include <Box2D/Dynamics/Contacts/b2Contact.h>

#include "CollisionListener.h"
#include "PhysicsWorldPosition.h"
#include "WorldObject.h"

#include "equipment/Projectile.h"

CollisionListener::CollisionListener()
{
}


void CollisionListener::BeginContact(b2Contact *contact)
{
	const b2Fixture *fixtureA = contact->GetFixtureA();
	const b2Fixture *fixtureB = contact->GetFixtureB();
	const b2Body *bodyA = fixtureA->GetBody();
	const b2Body *bodyB = fixtureB->GetBody();

	WorldObject *objectA = static_cast<WorldObject*>(bodyA->GetUserData());
	WorldObject *objectB = static_cast<WorldObject*>(bodyB->GetUserData());

	Projectile *projectileA = dynamic_cast<Projectile*>(objectA);
	Projectile *projectileB = dynamic_cast<Projectile*>(objectB);

	if(!fixtureA->IsSensor() && !fixtureB->IsSensor())
	{
		if(projectileA)
		{
			projectileA->onCollision(objectB);
			projectileA->deleteLater();
		}
		else if(projectileB)
		{
			projectileB->onCollision(objectA);
			projectileB->deleteLater();
		}
		else
		{
			objectA->onCollision(objectB);
			objectB->onCollision(objectA);
		}
	}
	else
	{
		if(fixtureA->IsSensor() && !fixtureB->IsSensor())
		{
			objectA->onSensorEnter(fixtureA, objectB);
		}
		else if(fixtureB->IsSensor() && !fixtureA->IsSensor())
		{
			objectB->onSensorEnter(fixtureB, objectA);
		}
	}
}

void CollisionListener::EndContact(b2Contact *contact)
{
	const b2Fixture *fixtureA = contact->GetFixtureA();
	const b2Fixture *fixtureB = contact->GetFixtureB();
	const b2Body *bodyA = fixtureA->GetBody();
	const b2Body *bodyB = fixtureB->GetBody();

	WorldObject *objectA = static_cast<WorldObject*>(bodyA->GetUserData());
	WorldObject *objectB = static_cast<WorldObject*>(bodyB->GetUserData());

	const PhysicsWorldPosition *pPositionA = dynamic_cast<const PhysicsWorldPosition*>(&objectA->worldPosition());
	const PhysicsWorldPosition *pPositionB = dynamic_cast<const PhysicsWorldPosition*>(&objectB->worldPosition());

	if((pPositionA && pPositionA->isDestroyed()) || (pPositionB && pPositionB->isDestroyed()))
	{
		return;
	}

	if(fixtureA->IsSensor() && !fixtureB->IsSensor())
	{
		objectA->onSensorLeave(fixtureA, objectB);
	}
	else if(fixtureB->IsSensor() && !fixtureA->IsSensor())
	{
		objectB->onSensorLeave(fixtureB, objectA);
	}
}

void CollisionListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
}

void CollisionListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{
}
