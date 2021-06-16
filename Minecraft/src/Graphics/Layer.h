#pragma once

namespace Minecraft {

	class Event;

	class Layer {

	public:
		Layer() = default;
		virtual ~Layer() = default;

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate(float dt) = 0;
		virtual void OnEvent(Event& event) = 0;
	};
}
