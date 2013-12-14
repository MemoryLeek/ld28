#include <QBuffer>
#include <QDebug>

#include "ImageWrapper.h"

ImageWrapper::ImageWrapper(const QImage image)
	: m_image(image)
{

}

QDataStream &operator <<(QDataStream &stream, const ImageWrapper &wrapper)
{
	QBuffer buffer;
	buffer.open(QIODevice::WriteOnly);

	QImage texture = wrapper.m_image;
	texture.save(&buffer, "PNG");

	QByteArray array = buffer.data();

	stream << array;

	qDebug() << array.count();

	return stream;
}
