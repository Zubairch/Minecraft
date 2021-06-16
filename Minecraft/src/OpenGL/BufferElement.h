#pragma once

namespace Minecraft { namespace API {

	struct BufferElement {

	public:
		GLuint type;
		GLuint size;
		GLuint count;
		GLuint offset;
		bool normalized;

		BufferElement()
			: type(0), size(0), count(0), offset(0), normalized(false) { }

		BufferElement(GLuint type, GLuint size, GLuint count, GLuint offset, bool normalized)
			: type(type), size(size), count(count), offset(offset), normalized(normalized) { }
	};
} }