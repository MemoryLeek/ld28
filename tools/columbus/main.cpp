#include <QGuiApplication>
#include <QStringList>
#include <QPainter>
#include <QDebug>
#include <QDir>

#include <tiled/map.h>
#include <tiled/mapreader.h>
#include <tiled/imagelayer.h>
#include <tiled/tilelayer.h>
#include <tiled/tile.h>

#include "QStringEx.h"
#include "RoomLoader.h"
#include "RoomLookup.h"
#include "RoomLookupPersister.h"
#include "TileObject.h"

int main(int argc, char **argv)
{
	QGuiApplication application(argc, argv);

	const QStringList &arguments = application.arguments();
	const QString &folder = arguments.value(1);

	if(!folder.isEmpty())
	{
		const QDir dir(folder);
		const QStringList filter = { "*.tmx" };
		const QStringList &files = dir.entryList(filter, QDir::Files);

		RoomLookup lookup;

		for(const QString &fileName : files)
		{
			const QString &path = QStringEx::format("%1/%2", folder, fileName);

			RoomLoader roomLoader;
			RoomObject *room = roomLoader.load(path);

			if(room)
			{
				lookup.addRoom(*room);
			}
		}

		RoomLookupPersister persister("world.wld");
		persister.persist(lookup);
	}
}
