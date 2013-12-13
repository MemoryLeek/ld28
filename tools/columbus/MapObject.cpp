#include "MapObject.h"

MapObject::MapObject()
{

}

void MapObject::addTile(TileObject tile)
{
	m_tiles << tile;
}
