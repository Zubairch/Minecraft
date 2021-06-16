#include <MC.h>

#include "Camera.h"

#include "Application/Application.h"
#include "Window/Input.h"

namespace Minecraft {

	Camera::Camera(const glm::mat4& projectionMatrix) {

		m_ProjectionMatrix = projectionMatrix;
		m_ViewMatrix = glm::mat4(1.0f);

		m_Position = { 0.0f, 0.0f, 3.0f };
		m_Front = { 0.0f, 0.0f, -1.0f };
		m_WorldUp = { 0.0f, 1.0f, 0.0f };

		auto size = Application::GetApplication()->GetWindowSize();

		m_LastMousePosition = { (float)size.x / 2.0f, (float)size.y / 2.0f };

		m_Yaw = -90.f;
		m_Pitch = 0.0f;
		m_Speed = 0.005f;
		m_MouseSensitivity = 0.1f;
	}

	void Camera::Update() {

		CalculateVectors();

		m_ViewMatrix = glm::lookAt(m_Position, m_Position + m_Front, m_Up);
	}

	void Camera::CalculateVectors() {

		float x = (float)glm::cos(glm::radians(m_Yaw)) * (float)glm::cos(glm::radians(m_Pitch));
		float y = (float)glm::sin(glm::radians(m_Pitch));
		float z = (float)glm::sin(glm::radians(m_Yaw)) * (float)glm::cos(glm::radians(m_Pitch));

		m_Front.x = x;
		m_Front.y = y;
		m_Front.z = z;

		m_Front = glm::normalize(m_Front);

		m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		m_Up = glm::normalize(glm::cross(m_Right, m_Front));
	}
}