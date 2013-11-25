#include "DrawableObject.h"

DrawableObject::DrawableObject(int x, int y, const sf::Texture &texture)
	: Sprite(texture)
{
	setPosition(x, y);
}

void DrawableObject::foo()
{

}
