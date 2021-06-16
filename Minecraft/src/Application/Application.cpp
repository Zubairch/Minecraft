#include <MC.h>

#include "Application.h"

#include "Window/Input.h"
#include "Graphics/Layer.h"
#include "Events/WindowEvent.h"
#include "Events/EventDispatcher.h"

namespace Minecraft {

	Application* Application::s_Instance = nullptr;

	Application::Application()
		: m_Window(), m_Running(true) { }

	void Application::Init(const eastl::string& appTitle) {

		m_Window = new Window(1280U, 720U, appTitle);

		m_Window->SetEventCallback([this](Event& event) {

			OnEvent(event);
		});

		Input::Init();
	}

	void Application::Shutdown() {

		Input::Shutdown();
		delete m_Window;
	}

	void Application::Run() {

		TimeStep timeStep(Timer::GetMillis());

		while (m_Running) {

			timeStep.Update(Timer::GetMillis());

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(timeStep.GetMillis());

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& event) {

		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& event) {

			return OnWindowClose(event);
		});

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {

			Layer* layer = *(--it);
			layer->OnEvent(event);
			
			if (event.Handled())
				break;
		}
	}

	void Application::PushLayer(Layer* layer) {

		m_LayerStack.PushLayer(layer);
	}

	bool Application::OnWindowClose(WindowCloseEvent& event) {

		m_Running = false;
		return true;
	}
}