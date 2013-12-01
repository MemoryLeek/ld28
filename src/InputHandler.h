#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <map>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

const float PI = 3.14159265359;

class SettingsHandler;

class InputHandler
{
	public:
		InputHandler(SettingsHandler *settingsHandler, sf::RenderWindow *window);

		void handle(const sf::Event &event);

	private:
		SettingsHandler *m_settingsHandler;
		sf::RenderWindow *m_window;
		std::map<int, float> m_axis;
};

#endif // INPUTHANDLER_H
