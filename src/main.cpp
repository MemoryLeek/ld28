#include <cmath>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "MapLoader.h"
#include "Map.h"
#include "PhysicsWorldPosition.h"
#include "Player.h"
#include "World.h"
#include "WorldDebug.h"
#include "WorldPosition.h"

int main()
{
	sf::VideoMode videoMode(800, 600);
	sf::RenderWindow window(videoMode, "My window");
	sf::View camera(sf::Rect<float>(0, 0, 800, 600));

	World world;

	WorldDebug worldDebugger(&window);
	worldDebugger.SetFlags(b2Draw::e_shapeBit);
	world.SetDebugDraw(&worldDebugger);

	WorldPosition *playerWorldPosition = world.createBox(b2Vec2(64, 64), 32, 32, b2_dynamicBody);
	Player player(playerWorldPosition);

	MapLoader mapLoader(&world);
	Map *map = mapLoader.load("resources/room.tmx");

	const float timestep = 1.f / 120.f; // 120Hz physics
	sf::Clock clock;
	int lastPhysicsStepTime;

	while(window.isOpen())
	{
		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
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
		player.update();
		while(clock.getElapsedTime().asMilliseconds() > lastPhysicsStepTime + timestep * 1000)
		{
			lastPhysicsStepTime += timestep * 1000;
			world.Step(timestep, 6, 2);
		}
		world.ClearForces();

		// Update camera position
		const b2Vec2 &playerPosition = playerWorldPosition->position();
		camera.setCenter(playerPosition.x, playerPosition.y);
		window.setView(camera);

		// Draw world
		window.clear();
		window.draw(*map);
		world.DrawDebugData();
		window.display();
	}

	return 0;
}
