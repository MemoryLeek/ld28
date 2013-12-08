#include <iostream>

#include "DefaultSettingsProvider.h"

Settings DefaultSettingsProvider::load()
{
	std::cout << "DEBUG: Loading defaults" << std::endl;

	Settings settings;
	InputMapping &inputMapping = settings.mapping();

	inputMapping
		.backwards()
		.setKey(sf::Keyboard::S);

	inputMapping
		.forward()
		.setKey(sf::Keyboard::W);

	inputMapping
		.left()
		.setKey(sf::Keyboard::A);

	inputMapping
		.right()
		.setKey(sf::Keyboard::D);

	return settings;
}

void DefaultSettingsProvider::save(const Settings &)
{

}
