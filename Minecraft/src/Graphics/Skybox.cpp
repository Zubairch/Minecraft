#include <MC.h>

#include "Skybox.h"

namespace Minecraft {

	Skybox::Skybox()
		: m_Size(100.0f) {
	
		Init();
	}

	Skybox::Skybox(float size)
		: m_Size(size) {
		
		Init();
	}

	void Skybox::Init() {

		eastl::vector<GLfloat> vertexData = {

			-m_Size,  m_Size, -m_Size,
			-m_Size, -m_Size, -m_Size,
			 m_Size, -m_Size, -m_Size,
			 m_Size, -m_Size, -m_Size,
			 m_Size,  m_Size, -m_Size,
			-m_Size,  m_Size, -m_Size,

			-m_Size, -m_Size,  m_Size,
			-m_Size, -m_Size, -m_Size,
			-m_Size,  m_Size, -m_Size,
			-m_Size,  m_Size, -m_Size,
			-m_Size,  m_Size,  m_Size,
			-m_Size, -m_Size,  m_Size,

			 m_Size, -m_Size, -m_Size,
			 m_Size, -m_Size,  m_Size,
			 m_Size,  m_Size,  m_Size,
			 m_Size,  m_Size,  m_Size,
			 m_Size,  m_Size, -m_Size,
			 m_Size, -m_Size, -m_Size,

			-m_Size, -m_Size,  m_Size,
			-m_Size,  m_Size,  m_Size,
			 m_Size,  m_Size,  m_Size,
			 m_Size,  m_Size,  m_Size,
			 m_Size, -m_Size,  m_Size,
			-m_Size, -m_Size,  m_Size,

			-m_Size,  m_Size, -m_Size,
			 m_Size,  m_Size, -m_Size,
			 m_Size,  m_Size,  m_Size,
			 m_Size,  m_Size,  m_Size,
			-m_Size,  m_Size,  m_Size,
			-m_Size,  m_Size, -m_Size,

			-m_Size, -m_Size, -m_Size,
			-m_Size, -m_Size,  m_Size,
			 m_Size, -m_Size, -m_Size,
			 m_Size, -m_Size, -m_Size,
			-m_Size, -m_Size,  m_Size,
			 m_Size, -m_Size,  m_Size
		};

		eastl::vector<GLuint> indexData(36);

		API::VertexBuffer* vertexBuffer = new API::VertexBuffer(API::VertexBuffer::BufferUsage::STATIC);
		API::IndexBuffer* indexBuffer = new API::IndexBuffer();

		API::BufferLayout layout;
		layout.Push(3, 3, false);

		indexBuffer->SetIndexData(indexData);

		vertexBuffer->SetVertexData(vertexData);
		vertexBuffer->SetBufferLayout(layout);

		m_VertexArray.PushBuffer(vertexBuffer);
		m_VertexArray.PushBuffer(indexBuffer);

		eastl::vector<eastl::string> files = {

			"../Resources/Textures/Skybox/right.jpg",
			"../Resources/Textures/Skybox/left.jpg",
			"../Resources/Textures/Skybox/top.jpg",
			"../Resources/Textures/Skybox/bottom.jpg",
			"../Resources/Textures/Skybox/front.jpg",
			"../Resources/Textures/Skybox/back.jpg"
		};

		m_CubeTexture.LoadTexture(files);
	}
}