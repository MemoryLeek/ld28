#ifndef STATICWORLDPOSITION_H
#define STATICWORLDPOSITION_H

#include "WorldPosition.h"

class StaticWorldPosition : public WorldPosition
{
	public:
		StaticWorldPosition(const b2Vec2 &position, const b2Vec2 &size);

		b2Vec2 position() const override;
		void setPosition(const b2Vec2 &position) override;

		float rotation() const override;
		void setRotation(float rotation) override;

		b2Vec2 size() const override;
		void setSize(const b2Vec2 &size) override;

	private:
		b2Vec2 m_position;
		b2Vec2 m_size;

		float m_rotation;
};

#endif // STATICWORLDPOSITION_H
