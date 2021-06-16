#include <MC.h>

#include "GameLayer.h"

#include "Events/EventDispatcher.h"

namespace Minecraft {

	GameLayer::GameLayer() {

		m_VertexArray = new API::VertexArray();
		m_Texture2D = new API::Texture2D("../Resources/Textures/Atlas.png");
		m_Shader = new API::Shader({ "../Resources/Shaders/vertex.glsl", "../Resources/Shaders/fragment.glsl" });

		m_World.Init();

		API::RenderCommand::DepthTest(true);
		API::RenderCommand::CullFace(true);
	}

	GameLayer::~GameLayer() {

		delete m_Shader;
		delete m_Texture2D;
		delete m_VertexArray;
	}

	void GameLayer::OnUpdate(float dt) {

		API::RenderCommand::Clear();
		API::RenderCommand::ClearColor();

		m_Texture2D->Bind();
		m_Shader->Bind();

		m_CameraController.OnUpdate(dt);

		m_Shader->SetUniformMat4f("u_Projection", m_CameraController.GetCamera().GetProjectionMatrix());
		m_Shader->SetUniformMat4f("u_View", m_CameraController.GetCamera().GetViewMatrix());

		m_World.Update(dt);
		
		m_SkyboxRenderer.BeginScene(m_CameraController.GetCamera());
		m_SkyboxRenderer.Submit();
		m_SkyboxRenderer.EndScene();
	}
	bool isJabbarBiper(eastl::string name) 
	{
		return(name == "Ibraheem");
	}
	bool isShafeeqTalli(eastl::string name) 
	{
		return(name == "Husnain");
	}
		bool isTufail(eastl::string name) {
			return(name == "Husnain");
	}
	void GameLayer::OnEvent(Event& event) {

		EventDispatcher dispatcher(event);

		dispatcher.Dispatch<WindowResizeEvent>([](WindowResizeEvent& event) {

			API::RenderCommand::SetViewPort(event.GetWidth(), event.GetHeight());
			return false;
		});

		m_CameraController.OnEvent(event);
	}
}