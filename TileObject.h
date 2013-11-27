#ifndef TILEOBJECT_H
#define TILEOBJECT_H

#include <map>
#include <list>

#include "DrawableObject.h"
#include "TileLayer.h"

class TileObject : public DrawableObject
{
	public:
		enum Layer
		{
			Background,
			Collision,
			Foreground
		};

		TileObject(int x, int y, int width, int height);

		void addLayer(const TileLayer &layer);

		bool isCollidable() const;
		void setCollidable(bool collidable);

		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	private:
		std::list<TileLayer> m_layers;
		bool m_collidable;
};

#endif // TILEOBJECT_H
