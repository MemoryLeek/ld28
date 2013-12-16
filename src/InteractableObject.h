#ifndef INTERACTABLEOBJECT_H
#define INTERACTABLEOBJECT_H

#include "AnimatedObject.h"

class Player;

class InteractableObject : public AnimatedObject
{
	public:
		InteractableObject(const sf::String &fileName, WorldPosition *position);
		virtual ~InteractableObject();

		void onCollision(WorldObject *other) override;
		void onSensorEnter(const b2Fixture *sensor, WorldObject *other) override;
		void onSensorLeave(const b2Fixture *sensor, WorldObject *other) override;

		virtual void onInteraction(Player &player) = 0;

		int drawingOrder() const override;
};

#endif // INTERACTABLEOBJECT_H
