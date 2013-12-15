#include <iostream>
#include <cmath>

#include "InputHandler.h"
#include "AnalogMapping.h"
#include "SettingsHandler.h"

InputHandler::InputHandler(SettingsHandler *settingsHandler, sf::RenderWindow *window)
	: m_settingsHandler(settingsHandler)
	, m_window(window)
{

}

void InputHandler::handle(const sf::Event &event)
{
	Settings &settings = m_settingsHandler->settings();
	InputMapping &inputMapping = settings.mapping();

	switch(event.type)
	{
		case sf::Event::MouseMoved:
		{
			const sf::Event::MouseMoveEvent &mouseEvent = event.mouseMove;
			const sf::Vector2<int> position(mouseEvent.x, mouseEvent.y);
			const sf::Vector2<float> &mapped = m_window->mapPixelToCoords(position);

			inputMapping
				.analog()
				.invokeAbsolute(mapped.x, mapped.y);

			break;
		}

		case sf::Event::JoystickMoved:
		{
			const sf::Event::JoystickMoveEvent &joystickEvent = event.joystickMove;

			switch(joystickEvent.axis)
			{
				case sf::Joystick::X:
				case sf::Joystick::Y:
				{
					m_axis[joystickEvent.axis] = joystickEvent.position;

					const float x = m_axis[sf::Joystick::X];
					const float y = m_axis[sf::Joystick::Y];

					inputMapping
						.analog()
						.invokeRelative(x, y);

					if(joystickEvent.position != 0)
					{
						inputMapping
							.forward()
							.onKeyDown();
					}
					else
					{
						inputMapping
							.forward()
							.onKeyUp();
					}

					break;
				}

				case sf::Joystick::Z:
				case sf::Joystick::R:
				{
					std::cout << "den andra" << joystickEvent.axis << std::endl;

					break;
				}

				default:
				{
					std::cout << "typ triggers?" << std::endl;

					break;
				}
			}

			break;
		}

		case sf::Event::KeyPressed:
		case sf::Event::JoystickButtonPressed:
		case sf::Event::MouseButtonPressed:
		{
			const KeyMapping *mapping = inputMapping.find(event);

			if(mapping)
			{
				mapping->onKeyDown();
			}

			break;
		}

		case sf::Event::KeyReleased:
		case sf::Event::JoystickButtonReleased:
		case sf::Event::MouseButtonReleased:
		{
			const KeyMapping *mapping = inputMapping.find(event);

			if(mapping)
			{
				mapping->onKeyUp();
			}

			break;
		}

		default:
		{
			break;
		}
	}
}
