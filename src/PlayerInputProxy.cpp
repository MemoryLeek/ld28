#include "PlayerInputProxy.h"
#include "Player.h"

PlayerInputProxy::PlayerInputProxy(Player *player)
	: m_player(player)
{

}

void PlayerInputProxy::absoluteInput(const float x, const float y)
{
	const WorldPosition &worldPosition = m_player->worldPosition();

	const b2Vec2 &position = worldPosition.position();
	const b2Vec2 relative(x - position.x, y - position.y);

	relativeInput(relative.x, relative.y);
}

void PlayerInputProxy::relativeInput(const float x, const float y)
{
	const float rotation = atan2(y, x) * 180 / M_PI;

	WorldPosition &position = m_player->worldPosition();
	position.setRotation(rotation);
}

void PlayerInputProxy::moveLeft()
{
	const b2Vec2 &movement = m_player->movement();
	const b2Vec2 value(movement.x, -2);

	m_player->setMovement(value);
}

void PlayerInputProxy::moveRight()
{
	const b2Vec2 &movement = m_player->movement();
	const b2Vec2 value(movement.x, 2);

	m_player->setMovement(value);
}

void PlayerInputProxy::moveForward()
{
	const b2Vec2 &movement = m_player->movement();
	const b2Vec2 value(2, movement.y);

	m_player->setMovement(value);
}

void PlayerInputProxy::moveBackwards()
{
	const b2Vec2 &movement = m_player->movement();
	const b2Vec2 value(-2, movement.y);

	m_player->setMovement(value);
}

void PlayerInputProxy::interact()
{
	m_player->interact();
}

void PlayerInputProxy::stopHorizontally()
{
	const b2Vec2 &movement = m_player->movement();
	const b2Vec2 value(movement.x, 0);

	m_player->setMovement(value);
}

void PlayerInputProxy::stopVertically()
{
	const b2Vec2 &movement = m_player->movement();
	const b2Vec2 value(0, movement.y);

	m_player->setMovement(value);
}

void PlayerInputProxy::nothing()
{

}
