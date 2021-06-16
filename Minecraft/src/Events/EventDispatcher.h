#pragma once

#include <MC.h>

#include "Event.h"

namespace Minecraft {

	class EventDispatcher {

	private:
		Event& m_Event;

	public:
		EventDispatcher(Event& event)
			: m_Event(event) { }

		template<typename T, typename EventFunction>
		bool Dispatch(const EventFunction& function) {

			if (m_Event.GetEventType() == T::GetStaticType()) {

				m_Event.m_Handled = function(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	};
}
