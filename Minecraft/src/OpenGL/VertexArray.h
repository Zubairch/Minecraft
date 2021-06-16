#pragma once

#include <MC.h>

#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace Minecraft { namespace API {

	class VertexArray {

	private:
		GLuint m_VertexArrayID;
		eastl::vector<VertexBuffer*> m_VertexBuffers;
		IndexBuffer* m_IndexBuffer;

	public:
		VertexArray();
		~VertexArray();

		void PushBuffer(VertexBuffer* vertexBuffer);
		void PushBuffer(IndexBuffer* IndexBuffer);

		void Bind() const;
		void UnBind() const;

		uint GetCount() const { return m_IndexBuffer->GetCount(); }
	};
} }
