#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "MapLoader.h"
#include "Map.h"

int main()
{
	sf::VideoMode videoMode(800, 600);
	sf::RenderWindow window(videoMode, "My window");

	MapLoader mapLoader;
	Map *map = mapLoader.load("resources/room.tmx");

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
		window.display();
	}

	return 0;
}
