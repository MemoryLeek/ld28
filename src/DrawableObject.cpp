#include "DrawableObject.h"
#include "Room.h"

DrawableObject::DrawableObject(WorldPosition *position)
	: WorldObject(position)
{

}

DrawableObject::~DrawableObject()
{

}

int DrawableObject::drawingOrder() const
{
	return 0;
}

bool DrawableObject::compare(WorldObject *d1, WorldObject *d2)
{
	DrawableObject *do1 = dynamic_cast<DrawableObject *>(d1);
	DrawableObject *do2 = dynamic_cast<DrawableObject *>(d2);

	if(do1 && do2)
	{
		return do1->drawingOrder() < do2->drawingOrder();
	}

	return true;
}
