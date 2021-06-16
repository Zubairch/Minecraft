#pragma once

#include <MC.h>

#include "Event.h"

namespace Minecraft {

	class MouseMovedEvent : public Event {

	private:
		glm::vec2 m_MousePosition;

	public:
		MouseMovedEvent(glm::vec2 position)
			: m_MousePosition(position) { }

		inline glm::vec2 GetMousePosition() const { return m_MousePosition; }

		inline float GetX() const { return m_MousePosition.x; }
		inline float GetY() const { return m_MousePosition.y; }

		static EventType GetStaticType() { return EventType::MouseMoved; }

		EventType GetEventType() const override { return GetStaticType(); }
		
	};

	class MouseButtonEvent : public Event {

	protected:
		uint m_Button;

	public:
		inline int GetMouseButton() const { return m_Button; }

	protected:
		MouseButtonEvent(uint button)
			: m_Button(button) { }
	};

	class MouseButtonPressedEvent : public MouseButtonEvent {

	public:
		MouseButtonPressedEvent(uint button)
			: MouseButtonEvent(button) { }

		static EventType GetStaticType() { return EventType::MouseButtonPressed; }

		EventType GetEventType() const override { return GetStaticType(); }
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {

	public:
		MouseButtonReleasedEvent(uint button)
			: MouseButtonEvent(button) {}

		static EventType GetStaticType() { return EventType::MouseButtonReleased; }

		EventType GetEventType() const override { return GetStaticType(); }
	};
}
