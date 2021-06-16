#include <MC.h>

#include "IndexBuffer.h"
#include "Error.h"

namespace Minecraft { namespace API {

	IndexBuffer::IndexBuffer()
		: m_Count(0) {
	
		GLCall(glGenBuffers(1, &m_IndexBufferID))
	}

	IndexBuffer::~IndexBuffer() {

		GLCall(glDeleteBuffers(1, &m_IndexBufferID))
	}

	void IndexBuffer::Bind() const {

		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID))
	}

	void IndexBuffer::UnBind() const {

		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_ZERO))
	}

	void IndexBuffer::SetIndexData(eastl::vector<GLuint> indexData) {

		m_Count = (GLuint)indexData.size();

		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID))
		GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(GLuint), indexData.data(), GL_STATIC_DRAW))
	}
} }