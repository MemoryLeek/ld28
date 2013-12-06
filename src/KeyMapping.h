#ifndef KEYMAPPING_H
#define KEYMAPPING_H

#include <fstream>
#include <functional>

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>

enum EventType
{
	Left,
	Right,
	Up,
	Down
};

template<class TInstance, class ...TArguments>
using Function = void (TInstance::*)();

class KeyMappingBase
{
	public:
		virtual EventType type() const = 0;

		int key() const;
		void setKey(const int key);

		int button() const;
		void setButton(const int button);

		void onKeyDown() const;
		void onKeyUp() const;

		template<class TInstance, class ...TArguments>
		void connect(TInstance *instance, Function<TInstance> keyDown, Function<TInstance> keyUp)
		{
			m_keyDown = std::bind(keyDown, instance);
			m_keyUp = std::bind(keyUp, instance);
		}

	protected:
		int m_key;
		int m_button;

	private:
		friend std::ifstream &operator >>(std::ifstream &stream, KeyMappingBase &mapping);
		friend std::ofstream &operator <<(std::ofstream &stream, KeyMappingBase &mapping);

		std::function<void()> m_keyDown;
		std::function<void()> m_keyUp;
};

template<EventType TType>
class KeyMapping : public KeyMappingBase
{
	public:
		EventType type() const
		{
			return TType;
		}

};

#endif // KEYMAPPING_H
