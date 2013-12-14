#ifndef COLLISIONLISTENER_H
#define COLLISIONLISTENER_H

#include <Box2D/Dynamics/b2WorldCallbacks.h>

class CollisionListener : public b2ContactListener
{
	public:
		CollisionListener();

		void BeginContact(b2Contact *contact) override;
		void EndContact(b2Contact *contact) override;
		void PreSolve(b2Contact *contact, const b2Manifold *oldManifold) override;
		void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse) override;
};

#endif // COLLISIONLISTENER_H
