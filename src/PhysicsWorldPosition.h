#ifndef PHYSICSWORLDPOSITION_H
#define PHYSICSWORLDPOSITION_H

#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2Fixture.h>

#include "World.h"
#include "WorldPosition.h"

class PhysicsWorldPosition : public WorldPosition
{
	public:
		b2Vec2 position() const override;
		void setPosition(const b2Vec2 &position) override;

		float rotation() const override;
		void setRotation(float rotation) override;

		b2Fixture *createRectangularSensor(int xOffset, int yOffset, int width, int height);
		b2Fixture *createCircularSensor(int radius);
		b2Fixture *createConeSensor(int length, int width);

		b2Body *body() const;

	private:
		PhysicsWorldPosition(b2Body *body);

		b2Body *m_body;

	friend class World;
};

#endif // PHYSICSWORLDPOSITION_H
