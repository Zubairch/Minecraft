#include <MC.h>

#include "InputManager.h"
#include "Application/Application.h"

namespace Minecraft {

	InputManager* InputManager::s_Instance = nullptr;

	void InputManager::Init() { }

	void InputManager::Shutdown() {

		delete s_Instance;
	}

	bool InputManager::IsKeyPressed(int key) const {
	
		auto window = (GLFWwindow*)Application::GetApplication()->GetWindowNativeHandle();
		int state = glfwGetKey(window, key);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool InputManager::IsButtonPressed(int button) const {

		auto window = (GLFWwindow*)Application::GetApplication()->GetWindowNativeHandle();
		int state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	glm::vec2 InputManager::GetMousePosition() const {

		auto window = (GLFWwindow*)Application::GetApplication()->GetWindowNativeHandle();
		
		double x, y;
		glfwGetCursorPos(window, &x, &y);

		return glm::vec2((float)x, (float)y);
	}

	void InputManager::SetMousePosition(const glm::vec2& position) {

		auto window = (GLFWwindow*)Application::GetApplication()->GetWindowNativeHandle();
		glfwSetCursorPos(window, position.x, position.y);
	}

	void InputManager::SetMouseCursor(MouseCursor cursor) {

		auto window = (GLFWwindow*)Application::GetApplication()->GetWindowNativeHandle();
		glfwSetInputMode(window, GLFW_CURSOR, ToGLFWCursorMode(cursor));
	}


	int InputManager::ToGLFWCursorMode(MouseCursor cursor) const {

		switch (cursor) {

			case MouseCursor::Normal:
				return GLFW_CURSOR_NORMAL;
			case MouseCursor::Hidden:
				return GLFW_CURSOR_HIDDEN;
			case MouseCursor::Disabled:
				return GLFW_CURSOR_DISABLED;
		}
		return GLFW_CURSOR_NORMAL;
	}
}