#pragma once

#include <MC.h>

#include "Skybox.h"
#include "IRenderer.h"

namespace Minecraft {

	class SkyboxRenderer : public IRenderer {

	private:
		Skybox m_Skybox;
		API::Shader* m_Shader;
		glm::mat4 m_ViewProjectionMatrix;

	public:
		SkyboxRenderer();
		~SkyboxRenderer();

		void BeginScene(const Camera& camera) override;
		void EndScene() override;

		void Submit() const override;

	private:
		void Init();
	};
}
