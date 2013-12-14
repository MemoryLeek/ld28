#ifndef DIRECTIONSELECTORSTRATEGY_H
#define DIRECTIONSELECTORSTRATEGY_H

#include <QRect>

#include "Direction.h"

class IDirectionSelectorStrategy
{
	public:
		virtual Direction::Value direction(const QRect &rect) const
		{
			const bool isValid = canHandle(rect);

			if(isValid)
			{
				return direction();
			}

			return Direction::None;
		}

	protected:
		virtual Direction::Value direction() const = 0;
		virtual bool canHandle(const QRect &rect) const = 0;
};

class LeftDirectionSelectorStrategy : public IDirectionSelectorStrategy
{
	public:
		Direction::Value direction() const override
		{
			return Direction::Left;
		}

		bool canHandle(const QRect &rect) const override
		{
			return !rect.x();
		}
};

class RightDirectionSelectorStrategy : public IDirectionSelectorStrategy
{
	public:
		Direction::Value direction() const override
		{
			return Direction::Right;
		}

		bool canHandle(const QRect &rect) const override
		{
			return rect.width() == rect.x();
		}
};

class TopDirectionSelectorStrategy : public IDirectionSelectorStrategy
{
	public:
		Direction::Value direction() const override
		{
			return Direction::Top;
		}

		bool canHandle(const QRect &rect) const override
		{
			return !rect.y();
		}
};

class BottomDirectionSelectorStrategy : public IDirectionSelectorStrategy
{
	public:
		Direction::Value direction() const override
		{
			return Direction::Bottom;
		}

		bool canHandle(const QRect &rect) const override
		{
			return rect.height() == rect.y();
		}
};

#endif // DIRECTIONSELECTORSTRATEGY_H
