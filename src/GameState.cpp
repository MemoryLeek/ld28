#include "GameState.h"
#include "InputMapping.h"
#include "Player.h"
#include "World.h"
#include "WorldPosition.h"
#include "PhysicsWorldPosition.h"
#include "PlayerInputProxy.h"
#include "MapLoader.h"
#include "Map.h"
#include "WorldDebug.h"
#include "StringEx.h"

#include "ai/Bot.h"

GameState::GameState(sf::RenderWindow *window)
	: m_window(window)
	, m_lastPhysicsStepTime(0)
	, m_fpsCount(0)
{
	const b2Vec2 playerPosition(64, 64);
	const b2Vec2 botPosition(576, 64);

	WorldDebug *worldDebugger = new WorldDebug(m_window);
	worldDebugger->SetFlags(b2Draw::e_shapeBit);

	World *world = new World();
	world->SetDebugDraw(worldDebugger);

	WorldPosition *playerWorldPosition = world->createBox(playerPosition, 32, 32, b2_dynamicBody);
	WorldPosition *botWorldPosition = world->createBox(botPosition, 32, 32, b2_dynamicBody);

	MapLoader mapLoader(world);

	m_map = mapLoader.load("resources/room.tmx");
	m_player = new Player(playerWorldPosition);
	m_bot = new Bot(botWorldPosition, { m_player });
	m_proxy = new PlayerInputProxy(m_player);
	m_world = world;

	// UI Initialization
	m_font.loadFromFile("resources/Oxygen-Regular.ttf");

	m_fpsText.setFont(m_font);
	m_fpsText.setCharacterSize(10);
}

void GameState::setupInput(InputMapping *mapping)
{
	AnalogMapping &analog = mapping->analog();

	KeyMappingBase &left = mapping->left();
	KeyMappingBase &right = mapping->right();
	KeyMappingBase &forward = mapping->forward();
	KeyMappingBase &backwards = mapping->backwards();

	analog.connect(m_proxy, &PlayerInputProxy::absoluteInput, &PlayerInputProxy::relativeInput);

	left.connect(m_proxy, &PlayerInputProxy::moveLeft, &PlayerInputProxy::stopHorizontally);
	left.setKey(sf::Keyboard::A);

	right.connect(m_proxy, &PlayerInputProxy::moveRight, &PlayerInputProxy::stopHorizontally);
	right.setKey(sf::Keyboard::D);

	forward.connect(m_proxy, &PlayerInputProxy::moveForward, &PlayerInputProxy::stopVertically);
	forward.setKey(sf::Keyboard::W);

	backwards.connect(m_proxy, &PlayerInputProxy::moveBackwards, &PlayerInputProxy::stopVertically);
	backwards.setKey(sf::Keyboard::S);
}

void GameState::update()
{
	for(int i = 0; shouldStep(); i++)
	{
		if(!i)
		{
			m_player->update();
			m_bot->update();
		}

		m_lastPhysicsStepTime += TIMESTEP * 1000;
		m_world->Step(TIMESTEP, 6, 2);
	}

	m_world->ClearForces();

	const int fpsTimer = m_fpsTimer
		.getElapsedTime()
		.asMilliseconds();

	if(fpsTimer > 500)
	{
		const sf::String &string = sf::StringEx::format("%1 FPS", m_fpsCount * 2);

		m_fpsText.setString(string);
		m_fpsTimer.restart();
		m_fpsCount = 0;
	}

	const b2Vec2 &playerPosition = m_player
		->worldPosition()
		->position();

	const sf::Vector2<unsigned int> &size = m_window->getSize();
	const sf::Rect<float> cameraRect(playerPosition.x - size.x / 2, playerPosition.y - size.y / 2, size.x, size.y);
	const sf::View cameraView(cameraRect);
	const sf::View &defaultView = m_window->getDefaultView();

	m_window->setView(cameraView);
	m_window->clear();
	m_window->draw(*m_map);

	m_world->DrawDebugData();

	m_window->setView(defaultView);
	m_window->draw(m_fpsText);
	m_window->display();

	m_fpsCount++;
}

bool GameState::shouldStep()
{
	const int o = m_lastPhysicsStepTime + TIMESTEP * 1000;
	const int f = m_clock
		.getElapsedTime()
		.asMilliseconds();

	return f > o;
}
