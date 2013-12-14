#ifndef MUTABLESPRITE_H
#define MUTABLESPRITE_H

#include "ImageWrapper.h"

class MutableSprite
{
	friend QDataStream &operator <<(QDataStream &stream, const MutableSprite &sprite);

	public:
		MutableSprite();

		void addFrame(const QImage image);
		void setDelay(const float delay);

		bool isValid() const;

	private:
		QList<ImageWrapper> m_frames;

		float m_delay;
		float m_index;
};

#endif // MUTABLESPRITE_H
