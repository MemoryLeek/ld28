#include "GameState.h"
#include "InputMapping.h"
#include "Player.h"
#include "World.h"
#include "WorldPosition.h"
#include "PhysicsWorldPosition.h"
#include "PlayerInputProxy.h"

GameState::GameState()
{
	b2Vec2 position(64, 64);

	World *world = new World();
	WorldPosition *p = world->createBox(position, 32, 32, b2_dynamicBody);

	m_player = new Player(p);
	m_proxy = new PlayerInputProxy(m_player);
	m_world = world;
}

void GameState::setupInput(InputMapping *mapping)
{
	AnalogMapping &analog = mapping->analog();

	KeyMappingBase &left = mapping->left();
	KeyMappingBase &right = mapping->right();
	KeyMappingBase &up = mapping->forward();
	KeyMappingBase &down = mapping->backwards();

	analog.connect(m_proxy, &PlayerInputProxy::absoluteInput, &PlayerInputProxy::relativeInput);
	left.connect(m_proxy, &PlayerInputProxy::moveLeft, &PlayerInputProxy::stopHorizontally);
	right.connect(m_proxy, &PlayerInputProxy::moveRight, &PlayerInputProxy::stopHorizontally);
	up.connect(m_proxy, &PlayerInputProxy::moveUp, &PlayerInputProxy::stopVertically);
	down.connect(m_proxy, &PlayerInputProxy::moveDown, &PlayerInputProxy::stopVertically);
}

void GameState::update()
{

}
