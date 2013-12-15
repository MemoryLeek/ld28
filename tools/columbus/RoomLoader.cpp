#include <QPixmap>
#include <QDebug>

#include <tiled/mapreader.h>
#include <tiled/tilelayer.h>
#include <tiled/tile.h>
#include <tiled/map.h>
#include <tiled/objectgroup.h>
#include <tiled/mapobject.h>

#include "RoomLoader.h"
#include "TileObject.h"
#include "TileFeature.h"
#include "Direction.h"
#include "DirectionSelectorStrategy.h"
#include "PropertyEnumMapper.h"
#include "MapType.h"
#include "MapObjectTypeMapper.h"

RoomLoader::RoomLoader()
{
	m_directionSelectorStrategies =
	{
		new LeftDirectionSelectorStrategy(),
		new RightDirectionSelectorStrategy(),
		new TopDirectionSelectorStrategy(),
		new BottomDirectionSelectorStrategy()
	};
}

Room *RoomLoader::load(const QString &path) const
{
	Tiled::MapReader reader;
	Tiled::Map *map = reader.readMap(path);

	if(map)
	{
		const int mapWidth = map->width() - 1;
		const int mapHeight = map->height() - 1;
		const int tileWidth = map->tileWidth();
		const int tileHeight = map->tileHeight();
		const int collisionIndex = map->layerCount() - 1;

		MapObjectTypeMapper mapper;
		MapType::Value mapType = PropertyEnumMapper<MapType::Value>::map(map, "type");
		Room *room = new Room(mapType, mapWidth, mapHeight);

		for(int x = 0; x < map->width(); x++)
		{
			for(int y = 0; y < map->height(); y++)
			{
				TileObject target(tileWidth, tileHeight);
				Coordinate coordinate(x, y);

				for(int i = 0; i < map->layerCount(); i++)
				{
					Tiled::Layer *layer = map->layerAt(i);
					Tiled::TileLayer *tileLayer = dynamic_cast<Tiled::TileLayer *>(layer);

					if(tileLayer)
					{
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

							target.setHasContent(true);
						}
						else
						{
							if(i == collisionIndex)
							{
								const QRect rect(x, y, mapWidth, mapHeight);

								for(const IDirectionSelectorStrategy *strategy : m_directionSelectorStrategies)
								{
									const Direction::Value &direction = strategy->direction(rect);

									if(direction != Direction::None)
									{
										room->setEntrance(direction, coordinate);
									}
								}
							}
						}
					}
					else
					{
						Tiled::ObjectGroup *objectLayer = dynamic_cast<Tiled::ObjectGroup *>(layer);

						if(objectLayer)
						{
							const QList<Tiled::MapObject *> &objects = objectLayer->objects();

							for(Tiled::MapObject *object : objects)
							{
								const QPointF &position = object->position();
								const QPointF current(x, y + 1);

								if(current == position)
								{
									Tiled::Tile *tile = object->tile();

									if(tile)
									{
										QPainter *painter = target.painter();
										QPixmap image = tile->image();
										QString typeName = object->type();

										painter->drawPixmap(0, 0, image);

										const int id = mapper.map(typeName);

										if(id > -1)
										{
											target.setMapObject(id);
										}
									}
								}
							}

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
