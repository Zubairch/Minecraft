#include <MC.h>

#include "VertexBuffer.h"
#include "Error.h"

namespace Minecraft { namespace API {

	VertexBuffer::VertexBuffer(BufferUsage usage) 
		: m_DrawUsage(usage) {
	
		GLCall(glGenBuffers(1, &m_VertexBufferID))
	}

	VertexBuffer::~VertexBuffer() {

		GLCall(glDeleteBuffers(1, &m_VertexBufferID))
	}

	void VertexBuffer::Bind() const {

		GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID))
	}

	void VertexBuffer::UnBind() const {

		GLCall(glBindBuffer(GL_ARRAY_BUFFER, GL_ZERO))
	}

	void VertexBuffer::SetVertexData(const eastl::vector<GLfloat>& vertexData) const {

		GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID))
		GLCall(glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(GLfloat), vertexData.data(), GLBufferUsage(m_DrawUsage)))
	}

	void VertexBuffer::SetVertexLayout() const {

		uint stride = m_BufferLayout.GetStride() * sizeof(GLfloat);

		const eastl::vector<BufferElement>& elements = m_BufferLayout.m_Layouts;

		for (int i = 0; i < elements.size(); i++) {

			const BufferElement& element = elements[i];

			GLCall(glEnableVertexAttribArray(i))
			GLCall(glVertexAttribPointer(i, element.size, element.type, element.normalized, stride, (const void*)(element.offset * sizeof(float))))
		}
	}
} }