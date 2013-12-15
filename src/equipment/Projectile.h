#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "DrawableObject.h"

class Map;

class Projectile : public DrawableObject
{
	public:
		Projectile(WorldPosition *position, Map &map);

		void onCollision(WorldObject *other) override;
		void onSensorEnter(const b2Fixture *sensor, WorldObject *other) override;
		void onSensorLeave(const b2Fixture *sensor, WorldObject *other) override;
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		bool update(const int delta) override;

		void deleteLater();

	private:
		Map &m_map;

		bool m_shouldBeDeleted;
};

#endif // PROJECTILE_H
