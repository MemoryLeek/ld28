#ifndef STATICWORLDPOSITION_H
#define STATICWORLDPOSITION_H

#include "WorldPosition.h"

class StaticWorldPosition : public WorldPosition
{
	public:
		StaticWorldPosition(const b2Vec2 &position);

		b2Vec2 position() const override;
		void setPosition(const b2Vec2 &position) override;

		float rotation() const override;
		void setRotation(float rotation) override;

	private:
		b2Vec2 m_position;
		float m_rotation;
};

#endif // STATICWORLDPOSITION_H
