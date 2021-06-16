#pragma once

#include <MC.h>

namespace Minecraft { namespace API {

	class IndexBuffer {

	private:
		GLuint m_IndexBufferID;
		GLuint m_Count;

	public:
		IndexBuffer();
		~IndexBuffer();

		void Bind() const;
		void UnBind() const;

		inline GLuint GetCount() const { return m_Count; }

		void SetIndexData(eastl::vector<GLuint> indexData);
	};
} }
