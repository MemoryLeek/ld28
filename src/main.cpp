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
#include "GameState.h"

int main()
{
	sf::VideoMode videoMode(800, 600);
	sf::RenderWindow window(videoMode, "My window");
	
	SettingsHandler settingsHandler("settings.dat");
	InputHandler inputHandler(&settingsHandler, &window);
	InputMapping &mapping = settingsHandler.mapping();

	GameState state(&window);
	state.setupInput(&mapping);

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
				case sf::Event::KeyReleased:
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
		}

		state.update();
	}

	return 0;
}
