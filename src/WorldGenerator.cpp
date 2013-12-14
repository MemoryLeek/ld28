#include <algorithm>
#include <random>
#include <iostream>
#include <functional>
#include <set>

#include "RoomLookup.h"
#include "RoomLookupLoader.h"
#include "WorldGenerator.h"
#include "MapLoader.h"
#include "Map.h"
#include "StringEx.h"
#include "WorldGeneratorContext.h"
#include "RoomSelectorPredicate.h"

WorldGenerator::WorldGenerator(MapLoader *mapLoader, const sf::String &fileName)
	: m_mapLoader(mapLoader)
	, m_fileName(fileName)
{

}

Map *WorldGenerator::generate()
{
	RoomLookupLoader loader(m_fileName);
	RoomLookup *lookup = loader.load();

	if(lookup)
	{
		Map *map = new Map();

		std::vector<Room> &rooms = lookup->rooms();
		std::set<int> generatedRooms;

		std::random_device device;
		std::mt19937 generator(device());
		std::shuffle(rooms.begin(), rooms.end(), generator);

		std::cout << "Shuffled rooms" << std::endl;

		Room &start = *std::find_if(rooms.begin(), rooms.end(), &Room::isStart);
//		Room &end = *std::find_if(rooms.begin(), rooms.end(), &Room::isEnd);

		WorldGeneratorContext context(generatedRooms);
		RoomObject *startObject = generate(start, rooms, context, map);

		map->addRoom(startObject);

		return map;
	}
	else
	{
		std::string string = sf::StringEx::format("Failed to load world definition file \"%1\"", m_fileName);
		std::cout << string << std::endl;

		return 0;
	}
}

RoomObject *WorldGenerator::generate(const Room &room, std::vector<Room> &rooms, WorldGeneratorContext &context, Map *map)
{
	std::map<Direction::Value, Coordinate> entrances = room.entrances();
	std::map<Direction::Value, Coordinate>::iterator iterator = entrances.begin();

	context.markAsGenerated(room);

	for(; iterator != entrances.end(); iterator++)
	{
		const Direction::Value direction = iterator->first;

		if(context.reverse() != direction)
		{
			const Direction::Value reverse = Direction::reverse(direction);
			const RoomSelectorPredicate predicate(reverse, context);

			const std::function<bool(const Room &)> func = std::bind(&RoomSelectorPredicate::predicate, predicate, std::placeholders::_1);
			const std::vector<Room>::iterator result = std::find_if(rooms.begin(), rooms.end(), func);

			if(result != rooms.end())
			{
				WorldGeneratorContext forked = context.fork(room, *result, direction);
				RoomObject *roomObject = generate(*result, rooms, forked, map);

				map->addRoom(roomObject);
			}
		}
	}

	return m_mapLoader->load(room, context);
}
