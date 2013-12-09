#include "KeyMapping.h"

KeyMapping::KeyMapping()
	: m_key(0)
	, m_button(0)
{

}

int KeyMapping::key() const
{
	return m_key;
}

void KeyMapping::setKey(const int key)
{
	m_key = key;
}

int KeyMapping::button() const
{
	return m_button;
}

void KeyMapping::setButton(const int button)
{
	m_button = button;
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
	stream >> mapping.m_button;

	return stream;
}

BinaryStream &operator <<(BinaryStream &stream, const KeyMapping &mapping)
{
	stream << mapping.m_key;
	stream << mapping.m_button;

	return stream;
}
