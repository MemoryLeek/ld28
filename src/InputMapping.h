#ifndef INPUTMAPPING_H
#define INPUTMAPPING_H

#include <SFML/Window/Event.hpp>

#include "KeyMapping.h"
#include "AnalogMapping.h"

class InputMapping
{
	public:
		InputMapping();

		AnalogMapping &analog();

		KeyMapping<Left> &left();
		KeyMapping<Right> &right();
		KeyMapping<Down> &backwards();
		KeyMapping<Up> &forward();

		const KeyMappingBase *find(const sf::Event &event) const;

	private:
		AnalogMapping m_analog;

		KeyMapping<Left> m_left;
		KeyMapping<Right> m_right;
		KeyMapping<Down> m_backwards;
		KeyMapping<Up> m_forward;
};

#endif // INPUTMAPPING_H
