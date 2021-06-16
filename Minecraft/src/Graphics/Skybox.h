#pragma once

#include "OpenGL/VertexArray.h"
#include "OpenGL/TextureCube.h"

namespace Minecraft {

	class Skybox {

	private:
		API::VertexArray m_VertexArray;
		API::TextureCube m_CubeTexture;
		float m_Size;

	public:
		Skybox();
		Skybox(float size);
		~Skybox() = default;

		const API::VertexArray& GetVertexArray() const { return m_VertexArray; }
		const API::TextureCube& GetTexture() const { return m_CubeTexture; }

	private:
		void Init();
	};
}
