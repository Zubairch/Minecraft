#pragma once

#include "Camera.h"

#include "Events/WindowEvent.h"

namespace Minecraft {

	class CameraController {

	private:
		float m_Fov;
		float m_AspectRatio;
		Camera m_Camera;

	public:
		CameraController();
		CameraController(float aspectRatio, float fov);
		~CameraController() = default;

		void OnUpdate(float dt);
		void OnEvent(Event& event);

		const Camera& GetCamera() const { return m_Camera; }
		
	private:
		bool OnWindowResized(WindowResizeEvent& event);
	};
}
