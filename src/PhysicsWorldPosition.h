#ifndef PHYSICSWORLDPOSITION_H
#define PHYSICSWORLDPOSITION_H

#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2Fixture.h>

#include "World.h"
#include "WorldPosition.h"

class PhysicsWorldPosition : public WorldPosition
{
	public:
		~PhysicsWorldPosition();

		b2Vec2 position() const override;
		void setPosition(const b2Vec2 &position) override;

		float rotation() const override;
		void setRotation(float rotation) override;

		bool isDestroyed() const;

		b2Vec2 size() const override;
		void setSize(const b2Vec2 &size) override;

		b2Fixture *createRectangularSensor(int xOffset, int yOffset, int width, int height);
		b2Fixture *createCircularSensor(int radius);
		b2Fixture *createConeSensor(int length, int width);

		b2Body *body() const;

		void suspendCollision();

	private:
		PhysicsWorldPosition(b2Body *body, b2Vec2 size);

		b2Body *m_body;
		bool m_destroyed;
		b2Vec2 m_size;

	friend class World;
};

#endif // PHYSICSWORLDPOSITION_H
