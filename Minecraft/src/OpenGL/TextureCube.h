#pragma once


#pragma once

#include <MC.h>

namespace Minecraft { namespace API {

	class TextureCube {

	private:
		GLuint m_TextureID;

	public:
		TextureCube();
		TextureCube(const eastl::vector<eastl::string>& filenames);
		~TextureCube();

		void Bind(GLuint slot = 0) const;
		void UnBind() const;

		bool LoadTexture(const eastl::vector<eastl::string>& filenames);

	private:
		void Init();
	};
} }