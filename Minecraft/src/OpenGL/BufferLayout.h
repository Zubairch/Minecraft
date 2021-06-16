#pragma once

#include <MC.h>

#include "BufferElement.h"

namespace Minecraft { namespace API {

	struct BufferLayout {

	public:
		eastl::vector<BufferElement> m_Layouts;
		GLuint m_Offset;

	public:
		BufferLayout()
			: m_Offset(0) { }

		~BufferLayout() = default;

		inline void Push(GLuint size, GLuint count, bool normalized) {

			m_Layouts.push_back(BufferElement(GL_FLOAT, size, count, m_Offset, normalized));
			m_Offset += size;
		}

		inline GLuint GetStride() const {

			GLuint stride = 0;

			if (m_Layouts.size() <= 1)
				return stride;

			for (size_t i = 0; i < m_Layouts.size(); i++)
				stride += m_Layouts[i].size;

			return stride;
		}
	};
} }