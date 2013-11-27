#ifndef PHYSICSWORLDPOSITION_H
#define PHYSICSWORLDPOSITION_H

#include <Box2D/Dynamics/b2Body.h>

#include "World.h"
#include "WorldPosition.h"

class PhysicsWorldPosition : public WorldPosition
{
	public:
		b2Vec2 position() const override;
		void setPosition(const b2Vec2 &position) override;

		float rotation() const override;
		void setRotation(float rotation) override;

		b2Body *body() const;

	private:
		PhysicsWorldPosition(b2Body *body);

		b2Body *m_body;

	friend class World;
};

#endif // PHYSICSWORLDPOSITION_H
