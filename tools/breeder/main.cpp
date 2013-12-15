#include <QCoreApplication>
#include <QImageReader>
#include <QDir>
#include <QDebug>
#include <QDataStream>
#include <QDomDocument>

#include "MutableSprite.h"
#include "MutableSpriteBundle.h"
#include "QStringEx.h"

MutableSprite generate(const QString &filename, const bool loop, const int delay)
{
	qDebug() << QStringEx::format("Processing file %1", filename);

	MutableSprite sprite;
	QFile file(filename);

	if(file.open(QIODevice::ReadOnly))
	{
		QImageReader reader(&file);
		sprite.setDelay(delay);
		sprite.setLoops(loop ? -1 : 1);

		for(int i = 0; i < reader.imageCount(); i++)
		{
			QImage frame = reader.read();

			sprite.addFrame(frame);
			reader.jumpToNextImage();
		}
	}
	else
	{
		qDebug() << QStringEx::format("Error opening file '%1' for reading", filename);
	}

	return sprite;
}

int main(int argc, char **argv)
{
	MutableSpriteBundle spriteBundle;
	QCoreApplication application(argc, argv);
	QString fileName = application
		.arguments()
		.value(1);

	if(!fileName.isEmpty())
	{
		QFile file(fileName);

		QFileInfo fileInfo(file);
		QString folder = fileInfo.path();

		if(file.open(QIODevice::ReadOnly))
		{
			QString error;
			QDomDocument document;
			document.setContent(&file, &error);

			if(error.isEmpty())
			{
				const QDomNodeList &images = document
					.firstChildElement("images")
					.elementsByTagName("image");

				for(int i = 0; i < images.count(); i++)
				{
					const QDomNode &node = images.at(i);
					const QString &imageFileName = node
						.firstChildElement("filename")
						.text();

					const bool loop = node
						.firstChildElement("loop")
						.text() == "true";

					const int delay = node
						.firstChildElement("delay")
						.text()
						.toInt();

					const QString &path = QStringEx::format("%1/%2", folder, imageFileName);
					const MutableSprite sprite = generate(path, loop, delay);

					if(sprite.isValid())
					{
						spriteBundle.addSprite(sprite);
					}
				}

				QString inputFileName = fileInfo.baseName();
				QString outputFileName = QStringEx::format("%1/%2.spb", folder, inputFileName);
				QFile outputFile(outputFileName);

				if(outputFile.open(QIODevice::WriteOnly))
				{
					QDataStream stream(&outputFile);
					stream.setFloatingPointPrecision(QDataStream::SinglePrecision);
					stream.setByteOrder(QDataStream::LittleEndian);
					stream << spriteBundle;
				}
				else
				{
					qDebug() << QStringEx::format("Error opening file '%1' for writing", fileName);
				}
			}
			else
			{
				qDebug() << QStringEx::format("Error parsing XML document: %1", error);
			}
		}
		else
		{
			qDebug() << QStringEx::format("Error opening file '%1' for reading", fileName);
		}
	}

	return 0;
}
