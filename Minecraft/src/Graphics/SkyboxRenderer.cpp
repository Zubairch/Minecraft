#include <MC.h>

#include "Camera/Camera.h"
#include "OpenGL/Shader.h"
#include "SkyboxRenderer.h"
#include "OpenGL/RenderCommand.h"

namespace Minecraft {

	SkyboxRenderer::SkyboxRenderer() {
	
		Init();
	}

	SkyboxRenderer::~SkyboxRenderer() {

		delete m_Shader;
	}

	void SkyboxRenderer::BeginScene(const Camera& camera) {

		m_ViewProjectionMatrix = camera.GetProjectionMatrix() * glm::mat4(glm::mat3(camera.GetViewMatrix()));
	}

	void SkyboxRenderer::EndScene() { }

	void SkyboxRenderer::Submit() const {

		API::RenderCommand::CullFace(false);
		API::RenderCommand::DepthFunction(GL_LEQUAL);

		m_Shader->Bind();
		m_Shader->SetUniformMat4f("u_ViewProjectionMatrix", m_ViewProjectionMatrix);

		m_Skybox.GetTexture().Bind();
		
		API::RenderCommand::Draw(m_Skybox.GetVertexArray());
			
		API::RenderCommand::DepthFunction(GL_LESS);
		API::RenderCommand::CullFace(true);
	}

	void SkyboxRenderer::Init() {

		eastl::vector<eastl::string> paths = {

			"../Resources/Shaders/SkyboxVertex.glsl",
			"../Resources/Shaders/SkyboxFragment.glsl"
		};

		m_Shader = new API::Shader(paths);
	}
}