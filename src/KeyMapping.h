#ifndef KEYMAPPING_H
#define KEYMAPPING_H

#include <fstream>
#include <functional>

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>

#include "BinaryStream.h"

template<class TInstance, class ...TArguments>
using Function = void (TInstance::*)();

class KeyMapping
{
	public:
		KeyMapping();

		int key() const;
		KeyMapping &setKey(const int key);

		int button() const;
		KeyMapping &setButton(const int button);

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
		friend BinaryStream &operator >>(BinaryStream &stream, KeyMapping &mapping);
		friend BinaryStream &operator <<(BinaryStream &stream, const KeyMapping &mapping);

		std::function<void()> m_keyDown;
		std::function<void()> m_keyUp;
};

#endif // KEYMAPPING_H
