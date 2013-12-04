#include <cmath>
#include <iostream>
#include <string>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

#include "ai/Bot.h"
#include "MapLoader.h"
#include "Map.h"
#include "PhysicsWorldPosition.h"
#include "Player.h"
#include "World.h"
#include "WorldDebug.h"
#include "WorldPosition.h"
#include "SettingsHandler.h"
#include "StringEx.h"
#include "InputHandler.h"

int main()
{
	sf::VideoMode videoMode(800, 600);
	sf::RenderWindow window(videoMode, "My window");
	sf::View camera(sf::Rect<float>(0, 0, 800, 600));

	sf::Font font;
	font.loadFromFile("resources/Oxygen-Regular.ttf");

	sf::Text fpsText("", font, 10);
	//fpsText.setFont(font);

	World world;

	WorldDebug worldDebugger(&window);
	worldDebugger.SetFlags(b2Draw::e_shapeBit);
	world.SetDebugDraw(&worldDebugger);

	WorldPosition *playerWorldPosition = world.createBox(b2Vec2(64, 64), 32, 32, b2_dynamicBody);
	Player player(playerWorldPosition);

	std::list<const WorldObject *> botEnemies = {&player};

	WorldPosition *botWorldPosition = world.createBox(b2Vec2(576, 64), 32, 32, b2_dynamicBody);
	Bot bot(botWorldPosition, &botEnemies);

	MapLoader mapLoader(&world);
	Map *map = mapLoader.load("resources/room.tmx");
	
	SettingsHandler settingsHandler("settings.dat");
	InputHandler inputHandler(&settingsHandler, &window);

	const float timestep = 1.f / 120.f; // 120Hz physics
	sf::Clock clock;
	int lastPhysicsStepTime;

	sf::Clock fpsTimer;
	int fpsCount;

	while(window.isOpen())
	{
		sf::Event event;

		while(window.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
				{
					window.close();

					break;
				}

				case sf::Event::MouseMoved:
				case sf::Event::KeyPressed:
				case sf::Event::JoystickButtonPressed:
				case sf::Event::JoystickButtonReleased:
				case sf::Event::JoystickMoved:
				{
					inputHandler.handle(event);

					break;
				}

				default:
				{
					break;
				}
			}

			if(event.type == sf::Event::MouseMoved)
			{
				const b2Vec2 &playerPosition = playerWorldPosition->position();
				const sf::Vector2<float> &mousePosition = window.mapPixelToCoords(sf::Vector2<int>(event.mouseMove.x, event.mouseMove.y));

				float faceDirection = atan2(mousePosition.y - playerPosition.y,
											mousePosition.x - playerPosition.x);

				playerWorldPosition->setRotation(faceDirection * 180 / M_PI);
			}

			if(event.type == sf::Event::KeyPressed)
			{
				const b2Vec2 &movement = player.movement();

				if(event.key.code == sf::Keyboard::W)
				{
					player.setMovement(b2Vec2(2, movement.y));
				}
				else if(event.key.code == sf::Keyboard::S)
				{
					player.setMovement(b2Vec2(-2, movement.y));
				}
				else if(event.key.code == sf::Keyboard::A)
				{
					player.setMovement(b2Vec2(movement.x, -2));
				}
				else if(event.key.code == sf::Keyboard::D)
				{
					player.setMovement(b2Vec2(movement.x, 2));
				}
			}

			if(event.type == sf::Event::KeyReleased)
			{
				const b2Vec2 &movement = player.movement();

				if(event.key.code == sf::Keyboard::W)
				{
					player.setMovement(b2Vec2(0, movement.y));
				}
				else if(event.key.code == sf::Keyboard::S)
				{
					player.setMovement(b2Vec2(0, movement.y));
				}
				else if(event.key.code == sf::Keyboard::A)
				{
					player.setMovement(b2Vec2(movement.x, 0));
				}
				else if(event.key.code == sf::Keyboard::D)
				{
					player.setMovement(b2Vec2(movement.x, 0));
				}
			}
		}

		// Update physics
		bool firstPhysicsStep = true;
		while(clock.getElapsedTime().asMilliseconds() > lastPhysicsStepTime + timestep * 1000)
		{
			if(firstPhysicsStep)
			{
				player.update();
				bot.update();
				firstPhysicsStep = false;
			}

			lastPhysicsStepTime += timestep * 1000;
			world.Step(timestep, 6, 2);
		}
		world.ClearForces();

		// Update camera position
		const b2Vec2 &playerPosition = playerWorldPosition->position();
		camera.setCenter(playerPosition.x, playerPosition.y);
		window.setView(camera);

		// Update FPS counter
		fpsCount++;
		if(fpsTimer.getElapsedTime().asMilliseconds() > 500)
		{
			fpsTimer.restart();
			fpsText.setString(sf::StringEx::format("%1 FPS", std::to_string(fpsCount * 2)));
			fpsCount = 0;
		}

		// Draw world
		window.clear();
		window.draw(*map);
		world.DrawDebugData();

		// Draw HUD stuff, reset camera after
		window.setView(window.getDefaultView());
		window.draw(fpsText);
		window.setView(camera);

		window.display();
	}

	return 0;
}
