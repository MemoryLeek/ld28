#include <iostream>

#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

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
	const float rotation = position.rotation();

	sf::Texture texture = *m_spriteBundle->currentImage();
	sf::Sprite sprite(texture);
	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(vector.x, vector.y);
	sprite.setRotation(rotation);
	target.draw(sprite);
}

bool AnimatedObject::update(const int delta)
{
	m_spriteBundle->update(delta);

	return true;
}
