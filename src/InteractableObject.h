#ifndef INTERACTABLEOBJECT_H
#define INTERACTABLEOBJECT_H

#include "DrawableObject.h"

class InteractableObject : public DrawableObject
{
	public:
		InteractableObject(WorldPosition *position);

		void onCollision(const WorldObject *other) override;
		void onSensorEnter(const b2Fixture *sensor, WorldObject *other) override;
		void onSensorLeave(const b2Fixture *sensor, WorldObject *other) override;

		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

		virtual void onInteraction() = 0;
};

#endif // INTERACTABLEOBJECT_H
