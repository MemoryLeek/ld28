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
	const b2Body *bodyA = contact->GetFixtureA()->GetBody();
	const b2Body *bodyB = contact->GetFixtureB()->GetBody();

	WorldObject *objectA = static_cast<WorldObject*>(bodyA->GetUserData());
	WorldObject *objectB = static_cast<WorldObject*>(bodyB->GetUserData());

	objectA->onCollision(objectB);
	objectB->onCollision(objectA);
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
