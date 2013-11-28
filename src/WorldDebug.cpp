#include <iostream>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>

#include "World.h"
#include "WorldDebug.h"

WorldDebug::WorldDebug(sf::RenderTarget *renderTarget)
	: m_renderTarget(renderTarget)
{
}

void WorldDebug::DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color)
{
	sf::ConvexShape polygon(vertexCount);
	for(int i = 0; i < vertexCount; i++)
	{
		polygon.setPoint(i, sf::Vector2f(vertices[i].x * World::SCALE, vertices[i].y * World::SCALE));
	}

	polygon.setOutlineColor(sf::Color(color.r, color.g, color.b, 127));
	polygon.setOutlineThickness(1);
	m_renderTarget->draw(polygon);
}

void WorldDebug::DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color)
{
	sf::ConvexShape polygon(vertexCount);
	for(int i = 0; i < vertexCount; i++)
	{
		polygon.setPoint(i, sf::Vector2f(vertices[i].x * World::SCALE, vertices[i].y * World::SCALE));
	}

	polygon.setFillColor(sf::Color(color.r, color.g, color.b, 127));
	m_renderTarget->draw(polygon);
}

void WorldDebug::DrawCircle(const b2Vec2 &center, float32 radius, const b2Color &color)
{
	sf::CircleShape circle;
	circle.setPosition(center.x * World::SCALE, center.y * World::SCALE);
	circle.setRadius(radius);
	circle.setOutlineColor(sf::Color(color.r, color.g, color.b, 127));
	circle.setOutlineThickness(1);
	m_renderTarget->draw(circle);
}

void WorldDebug::DrawSolidCircle(const b2Vec2 &center, float32 radius, const b2Vec2 &axis, const b2Color &color)
{
	sf::CircleShape circle;
	circle.setPosition(center.x * World::SCALE, center.y * World::SCALE);
	circle.setRadius(radius);
	circle.setFillColor(sf::Color(color.r, color.g, color.b, 127));
	m_renderTarget->draw(circle);
}

void WorldDebug::DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color)
{
	sf::Vertex line[] =	{sf::Vertex(sf::Vector2f(p1.x * World::SCALE, p1.y * World::SCALE)),
						 sf::Vertex(sf::Vector2f(p2.x * World::SCALE, p2.y * World::SCALE))};
	m_renderTarget->draw(line, 2, sf::Lines);
}

void WorldDebug::DrawTransform(const b2Transform &xf)
{
}
