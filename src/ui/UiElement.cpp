#include "UiElement.h"

UiElement::UiElement()
	: m_visible(true)
{

}

bool UiElement::isVisible() const
{
	return m_visible;
}

void UiElement::setVisible(const bool visible)
{
	m_visible = visible;
}
