#pragma once

#include "Window/Window.h"
#include "Events/WindowEvent.h"
#include "Graphics/LayerStack.h"

namespace Minecraft {

	class Application {

	private:
		static Application* s_Instance;

	private:
		Window* m_Window;
		LayerStack m_LayerStack;
		bool m_Running;

	public:
		Application();
		~Application() = default;

		void Init(const eastl::string& appTitle);
		void Shutdown();

		void Run();

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);

		inline static Application* GetApplication() { return s_Instance; }
		inline static Application* CreateApplication() { return s_Instance = new Application(); }

		inline static uint GetWdith() { return s_Instance->m_Window->GetWidth(); }
		inline static uint GetHeight() { return s_Instance->m_Window->GetWidth(); }

		inline static glm::uvec2 GetWindowSize() { return s_Instance->m_Window->GetWindowSize(); }
		inline static float GetWindowAspectRatio() { return s_Instance->m_Window->GetWindowAspectRatio(); }
		inline void* GetWindowNativeHandle() const { return m_Window->GetWindowNativeHandle(); }

	private:
		bool OnWindowClose(WindowCloseEvent& event);
	};
}

