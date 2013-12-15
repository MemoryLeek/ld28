#ifndef INPUTMAPPING_H
#define INPUTMAPPING_H

#include <SFML/Window/Event.hpp>

#include "KeyMapping.h"
#include "AnalogMapping.h"
#include "BinaryStream.h"

class InputMapping
{
	public:
		InputMapping();

		AnalogMapping &analog();

		KeyMapping &left();
		KeyMapping &right();
		KeyMapping &backwards();
		KeyMapping &forward();
		KeyMapping &action();

		KeyMapping &menuUp();
		KeyMapping &menuDown();
		KeyMapping &menuAccept();

		const KeyMapping *find(const sf::Event &event) const;

	private:
		friend BinaryStream &operator >>(BinaryStream &stream, InputMapping &mapping);
		friend BinaryStream &operator <<(BinaryStream &stream, const InputMapping &mapping);

		AnalogMapping m_analog;

		KeyMapping m_left;
		KeyMapping m_right;
		KeyMapping m_backwards;
		KeyMapping m_forward;
		KeyMapping m_action;

		KeyMapping m_menuUp;
		KeyMapping m_menuDown;
		KeyMapping m_menuAccept;
};

#endif // INPUTMAPPING_H
