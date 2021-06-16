
#include <MC.h>

#include "Window.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/WindowEvent.h"

namespace Minecraft {

	Window::Window(uint width, uint height, eastl::string title)
		: m_Width(width), m_Height(height), m_Title(title) {

		Init();
	}

	Window::~Window() {

		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void Window::OnUpdate() const {
		
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void Window::Init() {

		if (!glfwInit()) {
		
			// LOG THIS
			return;
		}

		glfwDefaultWindowHints();
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL);

		if (m_Window == NULL) {
		
			// LOG THIS
			return;
		}

		glfwMakeContextCurrent(m_Window);
		glfwShowWindow(m_Window);
		glfwSwapInterval(0);


		if (glewInit() != GLEW_OK) {

			// LOG THIS
			return;
		}

		glfwSetWindowUserPointer(m_Window, this);

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {

			auto win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Width = width;
			win->m_Height = height;

			win->m_EventCallback(WindowResizeEvent(glm::uvec2(width, height)));
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {

			auto win = (Window*)glfwGetWindowUserPointer(window);

			win->m_EventCallback(WindowCloseEvent());
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {

			auto win = (Window*)glfwGetWindowUserPointer(window);

			switch (action) {

				case GLFW_REPEAT:
				case GLFW_PRESS:
					win->m_EventCallback(KeyPressedEvent(key));
					break;

				case GLFW_RELEASE:
					win->m_EventCallback(KeyReleasedEvent(key));
					break;
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {

			auto win = (Window*)glfwGetWindowUserPointer(window);

			switch (action) {

				case GLFW_REPEAT:
				case GLFW_PRESS:
					win->m_EventCallback(MouseButtonPressedEvent(button));
					break;
				
				case GLFW_RELEASE:
					win->m_EventCallback(MouseButtonReleasedEvent(button));
					break;
			}
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos) {

			auto win = (Window*)glfwGetWindowUserPointer(window);

			win->m_EventCallback(MouseMovedEvent(glm::vec2((float)xPos, (float)yPos)));
		});
	}
}