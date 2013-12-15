#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "DrawableObject.h"

class Projectile : public DrawableObject
{
	public:
		Projectile(WorldPosition *position);

		void onCollision(const WorldObject *other) override;
		void onSensorEnter(const b2Fixture *sensor, WorldObject *other) override;
		void onSensorLeave(const b2Fixture *sensor, WorldObject *other) override;

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
		void update(const int delta) override;

		void deleteLater();

	private:
		bool m_shouldBeDeleted;
};

#endif // PROJECTILE_H
