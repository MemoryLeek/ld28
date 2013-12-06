#include <iostream>

#include "InputMapping.h"

InputMapping::InputMapping()
{

}

AnalogMapping &InputMapping::analog()
{
	return m_analog;
}

KeyMapping<Left> &InputMapping::left()
{
	return m_left;
}

KeyMapping<Right> &InputMapping::right()
{
	return m_right;
}

KeyMapping<Down> &InputMapping::backwards()
{
	return m_backwards;
}

KeyMapping<Up> &InputMapping::forward()
{
	return m_forward;
}

const KeyMappingBase *InputMapping::find(const sf::Event &event) const
{
	const KeyMappingBase *mappings[]
	{
		&m_left,
		&m_right,
		&m_backwards,
		&m_forward
	};

	for(const KeyMappingBase *mapping : mappings)
	{
		const int button = mapping->button();
		const int key = mapping->key();

		switch(event.type)
		{
			case sf::Event::JoystickButtonPressed:
			case sf::Event::JoystickButtonReleased:
			{
				std::cout << (int)event.joystickButton.button << std::endl;

				if(button == (int)event.joystickButton.button)
				{
					return mapping;
				}

				break;
			}

			case sf::Event::KeyPressed:
			case sf::Event::KeyReleased:
			{
				if(key == event.key.code)
				{
					return mapping;
				}

				break;
			}

			default:
			{
				break;
			}
		}
	}

	return 0;
}
