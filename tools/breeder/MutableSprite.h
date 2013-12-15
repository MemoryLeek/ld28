#ifndef MUTABLESPRITE_H
#define MUTABLESPRITE_H

#include "ImageWrapper.h"

class MutableSprite
{
	friend QDataStream &operator <<(QDataStream &stream, const MutableSprite &sprite);

	public:
		MutableSprite();

		void addFrame(const QImage image);
		void setDelay(const int delay);
		void setLoops(const int loops);

		bool isValid() const;

	private:
		QList<ImageWrapper> m_frames;

		float m_index;

		int m_delay;
		int m_loops;
};

#endif // MUTABLESPRITE_H
