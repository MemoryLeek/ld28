#include <iostream>

#include <Box2D/Dynamics/Contacts/b2Contact.h>

#include "CollisionListener.h"
#include "PhysicsWorldPosition.h"
#include "WorldObject.h"

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

	if(!fixtureA->IsSensor() && !fixtureB->IsSensor())
	{
		objectA->onCollision(objectB);
		objectB->onCollision(objectA);
	}
	else
	{
		if(fixtureA->IsSensor() && !fixtureB->IsSensor())
		{
			objectA->onSensorDetection(fixtureA, objectB);
		}
		else if(fixtureB->IsSensor() && !fixtureA->IsSensor())
		{
			objectB->onSensorDetection(fixtureB, objectA);
		}
	}
}

void CollisionListener::EndContact(b2Contact *contact)
{
}

void CollisionListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
}

void CollisionListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{
}
