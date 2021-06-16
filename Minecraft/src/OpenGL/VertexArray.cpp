#include <MC.h>

#include "VertexArray.h"
#include "Error.h"

namespace Minecraft { namespace API {

	VertexArray::VertexArray()
		: m_IndexBuffer(nullptr) {

		GLCall(glGenVertexArrays(1, &m_VertexArrayID))
	}

	VertexArray::~VertexArray() {

		for (size_t i = 0; i < m_VertexBuffers.size(); i++)
			delete m_VertexBuffers[i];

		if(m_IndexBuffer)
			delete m_IndexBuffer;

		GLCall(glDeleteVertexArrays(1, &m_VertexArrayID))
	}

	void VertexArray::PushBuffer(VertexBuffer* buffer) {

		GLCall(glBindVertexArray(m_VertexArrayID))
		buffer->Bind();

		buffer->SetVertexLayout();

		m_VertexBuffers.push_back(buffer);
	}

	void VertexArray::PushBuffer(IndexBuffer* buffer) {

		GLCall(glBindVertexArray(m_VertexArrayID))
		buffer->Bind();
		m_IndexBuffer = buffer;
	}

	void VertexArray::Bind() const {

		GLCall(glBindVertexArray(m_VertexArrayID))
	}

	void VertexArray::UnBind() const {

		GLCall(glBindVertexArray(GL_ZERO))
	}
} }


