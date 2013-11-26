#ifndef WORLDDEBUG_H
#define WORLDDEBUG_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics/RenderTarget.hpp>

class WorldDebug : public b2Draw
{
	public:
		WorldDebug(sf::RenderTarget *renderTarget);

		void DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) override;
		void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) override;
		void DrawCircle(const b2Vec2 &center, float32 radius, const b2Color &color) override;
		void DrawSolidCircle(const b2Vec2 &center, float32 radius, const b2Vec2 &axis, const b2Color &color) override;
		void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) override;
		void DrawTransform(const b2Transform &xf) override;

	private:
		sf::RenderTarget *m_renderTarget;
};

#endif // WORLDDEBUG_H
