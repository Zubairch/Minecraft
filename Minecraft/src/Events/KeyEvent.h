#pragma once

#include "Event.h"

namespace Minecraft {

	class KeyEvent : public Event {

	protected:
		uint m_KeyCode;

	public:
		inline uint GetKeyCode() const { return m_KeyCode; }

	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) { }

	};

	class KeyPressedEvent : public KeyEvent {

	public:
		KeyPressedEvent(int keycode)
			: KeyEvent(keycode) { }

		static EventType GetStaticType() { return EventType::KeyPressed; }

		EventType GetEventType() const override { return GetStaticType(); }
	};

	class KeyReleasedEvent : public KeyEvent {

	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		static EventType GetStaticType() { return EventType::KeyReleased; }

		EventType GetEventType() const override { return GetStaticType(); }
	};
}