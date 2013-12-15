#include <iostream>

#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "AnimatedObject.h"
#include "SpriteLoader.h"
#include "SpriteBundle.h"
#include "Room.h"

AnimatedObject::AnimatedObject(const sf::String &fileName, WorldPosition *worldPosition)
	: DrawableObject(worldPosition)
{
	SpriteLoader spriteLoader;
	SpriteBundle *spriteBundle = spriteLoader.load(fileName);

	m_spriteBundle = spriteBundle;
}

void AnimatedObject::setImageIndex(const int index)
{
	m_spriteBundle->setImageIndex(index);
}

void AnimatedObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	const WorldPosition &position = worldPosition();
	const b2Vec2 &vector = position.position();
	const b2Vec2 &size = position.size();
	const sf::Vertex vertices[]
	{
		sf::Vertex
		{
			sf::Vector2f(vector.x, vector.y),
			sf::Vector2f(0, 0)
		},
		sf::Vertex
		{
			sf::Vector2f(vector.x, vector.y + size.y),
			sf::Vector2f(0, size.y)
		},
		sf::Vertex
		{
			sf::Vector2f(vector.x + size.x, vector.y + size.y),
			sf::Vector2f(size.x, size.y)
		},
		sf::Vertex
		{
			sf::Vector2f(vector.x + size.x, vector.y),
			sf::Vector2f(size.x, 0)
		}
	};

	sf::Transform transform;
	transform.translate(-size.x / 2, -size.y / 2);

	states.texture = m_spriteBundle->currentImage();
	states.transform = transform;

	target.draw(vertices, 4, sf::Quads, states);
}

bool AnimatedObject::update(const int delta)
{
	m_spriteBundle->update(delta);

	return true;
}
