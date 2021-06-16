#include <MC.h>

#include "Window/Input.h"
#include "CameraController.h"
#include "Events/EventDispatcher.h"
#include "Application/Application.h"

namespace Minecraft {

	CameraController::CameraController()
		: m_AspectRatio(Application::GetApplication()->GetWindowAspectRatio()), 
		  m_Fov(70.0f), m_Camera(glm::perspective(glm::radians(m_Fov), m_AspectRatio, 0.1f, 1000.0f)) { }

	CameraController::CameraController(float aspectRatio, float fov)
		: m_AspectRatio(aspectRatio), m_Fov(fov),
		  m_Camera(glm::perspective(glm::radians(m_Fov), m_AspectRatio, 0.1f, 1000.0f)) { }

	void CameraController::OnUpdate(float dt) {

		glm::vec2 pos = Input::GetMousePosition();

		float deltaX = pos.x - m_Camera.m_LastMousePosition.x;
		float deltaY = m_Camera.m_LastMousePosition.y - pos.y;

		Input::SetMousePosition(m_Camera.m_LastMousePosition);

		m_Camera.m_Yaw += deltaX * m_Camera.m_MouseSensitivity;
		m_Camera.m_Pitch += deltaY * m_Camera.m_MouseSensitivity;

		// Avoids Gimbal lock
		if (m_Camera.m_Pitch > 89.0f) 
			m_Camera.m_Pitch = 89.0f;
		if (m_Camera.m_Pitch < -89.0f)
			m_Camera.m_Pitch = -89.0f;

		float velocity = m_Camera.m_Speed * dt;

		if (Input::IsKeyPressed(KEY_W))
			m_Camera.m_Position += m_Camera.m_Front * velocity;
		if (Input::IsKeyPressed(KEY_S))
			m_Camera.m_Position -= m_Camera.m_Front * velocity;
		if (Input::IsKeyPressed(KEY_A))
			m_Camera.m_Position -= m_Camera.m_Right * velocity;
		if (Input::IsKeyPressed(KEY_D))
			m_Camera.m_Position += m_Camera.m_Right * velocity;
		if (Input::IsKeyPressed(KEY_LEFT_SHIFT))
			m_Camera.m_Position += m_Camera.m_Up * velocity;
		if (Input::IsKeyPressed(KEY_LEFT_CONTROL))
			m_Camera.m_Position -= m_Camera.m_Up * velocity;

		m_Camera.Update();
	}

	void CameraController::OnEvent(Event& event) {

		EventDispatcher dispatcher(event);

		dispatcher.Dispatch<WindowResizeEvent>([this](WindowResizeEvent& event) {

			return OnWindowResized(event);
		});
	}

	bool CameraController::OnWindowResized(WindowResizeEvent& event) {

		float width = (float)event.GetWidth();
		float height = (float)event.GetHeight();

		m_Camera.m_LastMousePosition = { width / 2.0f, height / 2.0f };

		m_AspectRatio = width / height;
		m_Camera.m_ProjectionMatrix = glm::perspective(m_Fov, m_AspectRatio, 0.1f, 1000.f);

		return false;
	}
}