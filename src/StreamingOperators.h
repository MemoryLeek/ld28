#ifndef STREAMINGOPERATORS_H
#define STREAMINGOPERATORS_H

#include <fstream>
#include <list>

template<class T>
std::ofstream &operator <<(std::ofstream &stream, std::list<T> &list)
{
	stream << list.size();

	for(T &t : list)
	{
		stream << t;
	}

	return stream;
}

template<class T>
std::ifstream &operator >>(std::ifstream &stream, std::list<T> &list)
{
	size_t size;
	stream >> size;

	for(size_t i = 0; i < size; i++)
	{
		T t;
		stream >> t;

		list.push_back(t);
	}

	return stream;
}

#endif // STREAMINGOPERATORS_H
