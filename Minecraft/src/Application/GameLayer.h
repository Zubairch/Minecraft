#pragma once

#include "Window/Input.h"

#include "OpenGL/Shader.h"
#include "Graphics/Layer.h"
#include "OpenGL/Texture2D.h"
#include "OpenGL/VertexArray.h"
#include "Camera/CameraController.h"
#include "Graphics/SkyboxRenderer.h"

#include "Application/World/World.h"

namespace Minecraft {

	class GameLayer : public Layer {

	private:
		API::VertexArray* m_VertexArray;
		API::Shader* m_Shader;
		API::Texture2D* m_Texture2D;
		CameraController m_CameraController;
		SkyboxRenderer m_SkyboxRenderer;
		World m_World;

	public:
		GameLayer();
		~GameLayer();

		void OnAttach() override { Input::SetMouseCuror(MouseCursor::Hidden); }
		void OnDetach() override { Input::SetMouseCuror(MouseCursor::Normal); }
		void OnUpdate(float dt) override;
		void OnEvent(Event& event) override;

	};
}
