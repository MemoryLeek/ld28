#ifndef WORLDGENERATORCONTEXT_H
#define WORLDGENERATORCONTEXT_H

#include <set>

class Room;

class WorldGeneratorContext
{
	public:
		WorldGeneratorContext(std::set<int> &generatedRooms);
		WorldGeneratorContext(std::set<int> &generatedRooms, const int x, const int y);

		WorldGeneratorContext fork(const Room &current, const Room &next);

		bool isRoomGenerated(const Room &room) const;
		void markAsGenerated(const Room &room);

		int x() const;
		int y() const;

	private:
		std::set<int> &m_generatedRooms;

		int m_x;
		int m_y;
};

#endif // WORLDGENERATORCONTEXT_H
