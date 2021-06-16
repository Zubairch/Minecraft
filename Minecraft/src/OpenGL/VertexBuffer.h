#pragma once

#include <MC.h>

#include "BufferLayout.h"

namespace Minecraft { namespace API {

	class VertexBuffer {

	public:
		enum class BufferUsage { 
			STATIC = 0,
			DYNAMIC,
			STREAM
		};

	private:
		GLuint m_VertexBufferID;
		BufferUsage m_DrawUsage;
		BufferLayout m_BufferLayout;

	public:
		VertexBuffer() = default;
		VertexBuffer(BufferUsage drawUsage);
		~VertexBuffer();

		void Bind() const;
		void UnBind() const;

		void SetBufferLayout(const BufferLayout& layout) { m_BufferLayout = layout; }

		void SetVertexData(const eastl::vector<float>& vertexData) const;
		void SetVertexLayout() const;

	private:
		inline GLenum GLBufferUsage(BufferUsage drawUsage) const {

			switch (drawUsage) {

				case BufferUsage::STATIC:
					return GL_STATIC_DRAW;
				case BufferUsage::STREAM:
					return GL_STREAM_DRAW;
				case BufferUsage::DYNAMIC:
					return GL_DYNAMIC_DRAW;
				default:
					return GL_ZERO;
			}
		}
	};
} }
