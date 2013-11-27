#ifndef STRINGEX_H
#define STRINGEX_H

#include <list>
#include <string>
#include <sstream>
#include <algorithm>

#include <SFML/System/String.hpp>

namespace sf
{
	class StringEx
	{
		public:
			template<class ...TArguments>
			static sf::String format(const sf::String &format, TArguments ...arguments)
			{
				std::string target = format;
				std::list<std::string> strings = { arguments... };
				std::list<std::string>::const_iterator iterator = strings.begin();

				for(int i = 1; iterator != strings.end(); iterator++, i++)
				{
					std::ostringstream stream;
					stream << "%";
					stream << i;

					const std::string &placeholder = stream.str();
					const std::string &current = *iterator;

					const int position = target.find(placeholder);
					const int length = placeholder.length();

					target.replace(position, length, current);
				}

				return target;
			}
	};
}

#endif // STRINGEX_H
