#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "AnimatedObject.h"
#include "SpriteLoader.h"
#include "SpriteBundle.h"
#include "Room.h"

AnimatedObject::AnimatedObject(const sf::String &fileName, WorldPosition *worldPosition)
	: DrawableObject(worldPosition)
{
	sf::String f = getFilename(fileName, Direction::None);

	SpriteLoader spriteLoader;
	SpriteBundle *spriteBundle = spriteLoader.load(f);

	m_spriteBundle = spriteBundle;
}

void AnimatedObject::setImageIndex(const int index)
{
	m_spriteBundle->setImageIndex(index);
}

void AnimatedObject::update(const int delta)
{
	m_spriteBundle->update(delta);
}

void AnimatedObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	const WorldPosition &wp = worldPosition();
	const b2Vec2 &p = wp.position();
	const sf::Vertex vertices[]
	{
		sf::Vertex
		{
			sf::Vector2f(p.x, p.y),
			sf::Vector2f(0, 0)
		},
		sf::Vertex
		{
			sf::Vector2f(p.x, p.y + TILE_SIZE),
			sf::Vector2f(0, TILE_SIZE)
		},
		sf::Vertex
		{
			sf::Vector2f(p.x + TILE_SIZE, p.y + TILE_SIZE),
			sf::Vector2f(TILE_SIZE, TILE_SIZE)
		},
		sf::Vertex
		{
			sf::Vector2f(p.x + TILE_SIZE, p.y),
			sf::Vector2f(TILE_SIZE, 0)
		}
	};

	sf::Transform transform;
	transform.translate(-TILE_SIZE / 2, -TILE_SIZE / 2);

	states.texture = m_spriteBundle->currentImage();
	states.transform = transform;

	target.draw(vertices, 4, sf::Quads, states);
}

sf::String AnimatedObject::getFilename(const sf::String &fileName, const Direction::Value)
{
	return fileName;
}
