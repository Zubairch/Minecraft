#pragma once

#include <MC.h>

#include <Events/Event.h>

namespace Minecraft {

	class Window {

		using EventCallbackFunction = eastl::function<void(Event&)>;

	private:
		GLFWwindow* m_Window;
		uint m_Width;
		uint m_Height;
		eastl::string m_Title;

		EventCallbackFunction m_EventCallback;

	public:
		Window() = delete;
		Window(uint width, uint height, eastl::string title);
		~Window();

		void OnUpdate() const;

		void SetEventCallback(const EventCallbackFunction& callback) { m_EventCallback = callback; }

		inline uint GetWidth() const { return m_Width; }
		inline uint GetHeight() const { return m_Height; }

		inline float GetWindowAspectRatio() const { return (float)m_Width / m_Height; }

		inline glm::uvec2 GetWindowSize() const { return glm::uvec2(m_Width, m_Height); }
		inline void* GetWindowNativeHandle() const { return m_Window; }

	private:
		void Init();
	};
}
