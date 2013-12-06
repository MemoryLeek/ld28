#include "StringEx.h"

sf::StringToken::StringToken(const std::string &value)
{
	m_value = value;
}

sf::StringToken::StringToken(const sf::String &value)
{
	m_value = value;
}

sf::StringToken::StringToken(const int value)
{
	m_value = std::to_string(value);
}

sf::StringToken::operator std::string() const
{
	return m_value;
}
