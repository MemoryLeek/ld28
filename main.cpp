#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "MapLoader.h"
#include "Map.h"
#include "World.h"
#include "WorldDebug.h"

int main()
{
	sf::VideoMode videoMode(800, 600);
	sf::RenderWindow window(videoMode, "My window");

	World world;

	WorldDebug worldDebugger(&window);
	worldDebugger.SetFlags(b2Draw::e_shapeBit);
	world.SetDebugDraw(&worldDebugger);

	MapLoader mapLoader;
	Map *map = mapLoader.load("resources/room.tmx", world);

	while(window.isOpen())
	{
		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(*map);
		world.DrawDebugData();
		window.display();
	}

	return 0;
}
