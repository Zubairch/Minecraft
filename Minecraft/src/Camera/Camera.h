#pragma once

#include <MC.h>

namespace Minecraft {

	class Camera {

		friend class CameraController;

	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;

		glm::vec3 m_Position;
		glm::vec3 m_Front;
		glm::vec3 m_Right;
		glm::vec3 m_Up;
		glm::vec3 m_WorldUp;

		glm::vec2 m_LastMousePosition;

		float m_Yaw;
		float m_Pitch;

		float m_Speed;
		float m_MouseSensitivity;

	public:
		Camera(const glm::mat4& projectionMatrix);
		~Camera() = default;

		void Update();

		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }

	private:
		void CalculateVectors();
	};
}