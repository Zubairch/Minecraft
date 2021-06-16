#pragma once

#include <MC.h>

#include "Event.h"

namespace Minecraft {

	class WindowResizeEvent : public Event {

	private:
		glm::uvec2 m_WindowSize;

	public:
		WindowResizeEvent(glm::uvec2 size)
			: m_WindowSize(size) { }

		inline glm::uvec2 GetWindowSize() const { return m_WindowSize; }

		inline uint GetWidth() const { return m_WindowSize.x; }
		inline uint GetHeight() const { return m_WindowSize.y; }

		static EventType GetStaticType() { return EventType::WindowResize; }

		EventType GetEventType() const override { return GetStaticType(); }
	};

	class WindowCloseEvent : public Event {

	public:
		WindowCloseEvent() { }

		static EventType GetStaticType() { return EventType::WindowClose; }

		EventType GetEventType() const override { return GetStaticType(); }
	};
}