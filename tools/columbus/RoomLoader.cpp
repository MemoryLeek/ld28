#include <QPixmap>
#include <QDebug>

#include <tiled/mapreader.h>
#include <tiled/tilelayer.h>
#include <tiled/tile.h>
#include <tiled/map.h>

#include "RoomLoader.h"
#include "TileObject.h"

RoomLoader::RoomLoader()
{

}

RoomObject *RoomLoader::load(const QString &path) const
{
	Tiled::MapReader reader;
	Tiled::Map *map = reader.readMap(path);

	const int tileWidth = map->tileWidth();
	const int tileHeight = map->tileHeight();
	const int collisionIndex = map->layerCount() - 1;

	if(map)
	{
		RoomObject *room = new RoomObject();

		for(int x = 0; x < map->width(); x++)
		{
			for(int y = 0; y < map->height(); y++)
			{
				Tile target(tileWidth, tileHeight);
				Coordinate coordinate(x, y);

				for(int i = 0; i < map->layerCount(); i++)
				{
					Tiled::Layer *layer = map->layerAt(i);
					Tiled::TileLayer *tileLayer = (Tiled::TileLayer *)layer;
					Tiled::Cell cell = tileLayer->cellAt(x, y);
					Tiled::Tile *tile = cell.tile;

					if(tile)
					{
						QPainter *painter = target.painter();
						QPixmap image = tile->image();

						painter->drawPixmap(0, 0, image);

						if(i == collisionIndex)
						{
							target.setCollidable(true);
						}
					}
				}

				room->addTile(coordinate, target);
			}
		}

		qDebug() << path;

		return room;
	}
	else
	{
		return 0;
	}
}
