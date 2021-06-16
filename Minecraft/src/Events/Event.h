#pragma once

#include <MC.h>

namespace Minecraft {

	enum class EventType {

		None = 0,

		WindowClose, WindowResize,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved,

		EventCount
	};

	class Event {

		friend class EventDispatcher;

	protected:
		bool m_Handled = false;

	public:
		virtual EventType GetEventType() const = 0;

		inline bool Handled() const { return m_Handled; }
	};
}