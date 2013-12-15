#ifndef UIELEMENT_H
#define UIELEMENT_H

#include <SFML/Graphics/Drawable.hpp>

class UiElement : public sf::Drawable
{
	public:
		UiElement();

		bool isVisible() const;
		void setVisible(const bool visible);

	private:
		bool m_visible;
};

#endif // UIELEMENT_H
