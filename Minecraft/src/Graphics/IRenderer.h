#pragma once

#include <MC.h>

#include "Events/Event.h"
#include "Camera/Camera.h"

namespace Minecraft {

	class IRenderer {

	public:
		IRenderer() = default;
		virtual ~IRenderer() = default;

		virtual void BeginScene(const Camera& camera) = 0;
		virtual void EndScene() = 0;

		virtual void Submit() const = 0;

		virtual void OnEvent(Event& event) { }
	};
}