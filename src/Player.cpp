#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "PhysicsWorldPosition.h"
#include "Player.h"

Player::Player(WorldPosition *position)
	: DrawableObject(position, 32, 32)
{
}


void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
}

void Player::setLinearVelocity(const b2Vec2 &velocity)
{
	PhysicsWorldPosition *physicsWorldPosition = static_cast<PhysicsWorldPosition*>(worldPosition());
	b2Body *body = physicsWorldPosition->body();

	body->SetLinearVelocity(body->GetWorldVector(velocity));
}
