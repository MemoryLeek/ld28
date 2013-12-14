#include "GameState.h"
#include "InputMapping.h"
#include "Player.h"
#include "World.h"
#include "WorldPosition.h"
#include "PhysicsWorldPosition.h"
#include "PlayerInputProxy.h"
#include "MapLoader.h"
#include "RoomObject.h"
#include "WorldDebug.h"
#include "StringEx.h"
#include "CollisionListener.h"
#include "Map.h"
#include "TreasureContainer.h"

#include "ai/HumanoidBot.h"
#include "ai/Pathfinder.h"

#include <WorldGenerator.h>

GameState::GameState(sf::RenderWindow *window)
	: m_window(window)
	, m_lastPhysicsStepTime(0)
	, m_fpsCount(0)
{
	const b2Vec2 playerPosition(64, 64);
	const b2Vec2 botPosition(576, 64);
	const b2Vec2 treasurePosition(256, 64);

	WorldDebug *worldDebugger = new WorldDebug(m_window);
	worldDebugger->SetFlags(b2Draw::e_shapeBit);

	CollisionListener *collisionListener = new CollisionListener();

	World *world = new World();
	world->SetDebugDraw(worldDebugger);
	world->SetContactListener(collisionListener);

	PhysicsWorldPosition *playerWorldPosition = world->createBox(playerPosition, 32, 32, b2_dynamicBody);
	PhysicsWorldPosition *treasureWorldPosition = world->createBox(treasurePosition, 32, 32, b2_staticBody);
	WorldPosition *botWorldPosition = world->createCircle(botPosition, 16, b2_dynamicBody);
	//TreasureContainer *treasureContainer = TreasureContainer

	Pathfinder *pathfinder = new Pathfinder();
	MapLoader mapLoader(world, pathfinder);
	WorldGenerator worldGenerator(&mapLoader, "resources/world.wld");

	m_map = worldGenerator.generate();
	m_player = new Player(playerWorldPosition);
	m_bot = new HumanoidBot(botWorldPosition, { m_player }, pathfinder);
	m_proxy = new PlayerInputProxy(m_player);
	m_world = world;
	m_pathfinder = pathfinder;

	TreasureContainer *treasureContainer = new TreasureContainer(treasureWorldPosition);
	playerWorldPosition->createRectangularSensor(64, 64);

	// UI Initialization
	m_font.loadFromFile("resources/Oxygen-Regular.ttf");

	m_fpsText.setFont(m_font);
	m_fpsText.setCharacterSize(10);
}

void GameState::setupInput(InputMapping *mapping)
{
	AnalogMapping &analog = mapping->analog();

	KeyMapping &left = mapping->left();
	KeyMapping &right = mapping->right();
	KeyMapping &forward = mapping->forward();
	KeyMapping &backwards = mapping->backwards();
	KeyMapping &interact = mapping->interact();

	analog.connect(m_proxy, &PlayerInputProxy::absoluteInput, &PlayerInputProxy::relativeInput);
	left.connect(m_proxy, &PlayerInputProxy::moveLeft, &PlayerInputProxy::stopHorizontally);
	right.connect(m_proxy, &PlayerInputProxy::moveRight, &PlayerInputProxy::stopHorizontally);
	forward.connect(m_proxy, &PlayerInputProxy::moveForward, &PlayerInputProxy::stopVertically);
	backwards.connect(m_proxy, &PlayerInputProxy::moveBackwards, &PlayerInputProxy::stopVertically);
	interact.connect(m_proxy, &PlayerInputProxy::interact, &PlayerInputProxy::nothing);
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

	const b2Vec2 &playerPosition = (*m_player)
		.worldPosition()
		.position();

	const sf::Vector2<unsigned int> &size = m_window->getSize();
	const sf::Rect<float> cameraRect(playerPosition.x - size.x / 2, playerPosition.y - size.y / 2, size.x, size.y);
	const sf::View cameraView(cameraRect);
	const sf::View &defaultView = m_window->getDefaultView();

	m_window->setView(cameraView);
	m_window->clear();
	m_window->draw(*m_map);

	m_world->DrawDebugData();
	m_window->draw(*m_bot);

	m_window->setView(defaultView);
	m_window->draw(m_fpsText);

	m_window->setView(cameraView);
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
