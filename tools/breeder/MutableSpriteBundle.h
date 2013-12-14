#ifndef MUTABLESPRITEBUNDLE_H
#define MUTABLESPRITEBUNDLE_H

#include "MutableSprite.h"

class MutableSpriteBundle
{
	friend QDataStream &operator <<(QDataStream &stream, const MutableSpriteBundle &bundle);

	public:
		MutableSpriteBundle();

		void addSprite(const MutableSprite sprite);

	private:
		QList<MutableSprite> m_sprites;
};

#endif // MUTABLESPRITEBUNDLE_H
