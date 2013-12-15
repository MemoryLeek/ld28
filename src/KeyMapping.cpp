#include "KeyMapping.h"

KeyMapping::KeyMapping()
	: m_key(-1)
	, m_joystickButton(-1)
	, m_mouseButton(-1)
{

}

int KeyMapping::key() const
{
	return m_key;
}

KeyMapping &KeyMapping::setKey(const int key)
{
	m_key = key;

	return *this;
}

int KeyMapping::joystickButton() const
{
	return m_joystickButton;
}

KeyMapping &KeyMapping::setJoystickButton(const int button)
{
	m_joystickButton = button;

	return *this;
}

int KeyMapping::mouseButton() const
{
	return m_mouseButton;
}

KeyMapping &KeyMapping::setMouseButton(const int mouseButton)
{
	m_mouseButton = mouseButton;

	return *this;
}

void KeyMapping::onKeyDown() const
{
	if(m_keyDown)
	{
		m_keyDown();
	}
}

void KeyMapping::onKeyUp() const
{
	if(m_keyUp)
	{
		m_keyUp();
	}
}

BinaryStream &operator >>(BinaryStream &stream, KeyMapping &mapping)
{
	stream >> mapping.m_key;
	stream >> mapping.m_joystickButton;
	stream >> mapping.m_mouseButton;

	return stream;
}

BinaryStream &operator <<(BinaryStream &stream, const KeyMapping &mapping)
{
	stream << mapping.m_key;
	stream << mapping.m_joystickButton;
	stream << mapping.m_mouseButton;

	return stream;
}
