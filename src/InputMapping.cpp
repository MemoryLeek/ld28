#include <iostream>

#include "InputMapping.h"

InputMapping::InputMapping()
{

}

AnalogMapping &InputMapping::analog()
{
	return m_analog;
}

KeyMapping &InputMapping::left()
{
	return m_left;
}

KeyMapping &InputMapping::right()
{
	return m_right;
}

KeyMapping &InputMapping::backwards()
{
	return m_backwards;
}

KeyMapping &InputMapping::forward()
{
	return m_forward;
}

KeyMapping &InputMapping::interact()
{
	return m_interact;
}

KeyMapping &InputMapping::menuUp()
{
	return m_menuUp;
}

KeyMapping &InputMapping::menuDown()
{
	return m_menuDown;
}

KeyMapping &InputMapping::menuAccept()
{
	return m_menuAccept;
}

const KeyMapping *InputMapping::find(const sf::Event &event) const
{
	const KeyMapping *mappings[]
	{
		&m_left,
		&m_right,
		&m_backwards,
		&m_forward,
		&m_interact
	};

	for(const KeyMapping *mapping : mappings)
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

BinaryStream &operator >>(BinaryStream &stream, InputMapping &mapping)
{
	stream >> mapping.m_left;
	stream >> mapping.m_right;
	stream >> mapping.m_backwards;
	stream >> mapping.m_forward;
	stream >> mapping.m_interact;

	return stream;
}

BinaryStream &operator <<(BinaryStream &stream, const InputMapping &mapping)
{
	stream << mapping.m_left;
	stream << mapping.m_right;
	stream << mapping.m_backwards;
	stream << mapping.m_forward;
	stream << mapping.m_interact;

	return stream;
}
