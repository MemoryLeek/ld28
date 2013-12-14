#ifndef IMAGEWRAPPER_H
#define IMAGEWRAPPER_H

#include <QImage>

class ImageWrapper
{
	friend QDataStream &operator <<(QDataStream &stream, const ImageWrapper &wrapper);

	public:
		ImageWrapper(const QImage image);

	private:
		QImage m_image;
};

#endif // IMAGEWRAPPER_H
