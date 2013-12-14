#ifndef DIRECTION_H
#define DIRECTION_H

#include "BinaryStream.h"

struct Direction
{
	enum Value
	{
		None = 0,
		Left = 1,
		Right = 2,
		Top = 3,
		Bottom = 4
	};

	static Value reverse(Value value)
	{
		switch(value)
		{
			case Left:
			{
				return Right;
			}

			case Right:
			{
				return Left;
			}

			case Top:
			{
				return Bottom;
			}

			case Bottom:
			{
				return Top;
			}

			default:
			{
				return None;
			}
		}
	}
};

BinaryStream &operator >>(BinaryStream &stream, Direction::Value &direction);

#endif // DIRECTION_H
