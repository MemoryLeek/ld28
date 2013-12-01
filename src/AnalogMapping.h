#ifndef ANALOGMAPPING_H
#define ANALOGMAPPING_H

#include <functional>

class AnalogMapping
{
	template<class TInstance>
	using Function = void (TInstance::*)(float, float);

	public:
		AnalogMapping();

		void invokeAbsolute(const float x, const float y);
		void invokeRelative(const float x, const float y);

		template<class TInstance>
		void connect(TInstance *instance, Function<TInstance> absolute, Function<TInstance> relative)
		{
			m_absolute = std::bind(absolute, instance, std::placeholders::_1, std::placeholders::_2);
			m_relative = std::bind(relative, instance, std::placeholders::_1, std::placeholders::_2);
		}

	private:
		std::function<void(float, float)> m_absolute;
		std::function<void(float, float)> m_relative;
};

#endif // ANALOGMAPPING_H
