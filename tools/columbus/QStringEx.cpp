#include "QStringEx.h"

StringToken::StringToken(const QString &value)
{
	m_value = value;
}

StringToken::StringToken(const int value)
{
	m_value = QString::number(value);
}

StringToken::operator QString() const
{
	return m_value;
}
