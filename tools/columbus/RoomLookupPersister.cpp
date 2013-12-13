#include <QFile>

#include "RoomLookupPersister.h"

RoomLookupPersister::RoomLookupPersister(const QString &fileName)
	: m_fileName(fileName)
{

}

void RoomLookupPersister::persist(RoomLookup lookup)
{
	QFile file(m_fileName);

	if(file.open(QIODevice::WriteOnly))
	{
		QDataStream stream(&file);
		stream.setByteOrder(QDataStream::LittleEndian);
		stream << lookup;

		file.close();
	}
}
