#include <MC.h>

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#pragma warning(disable : 26451 6011)
#include <STBImage.h>
#pragma warning(default : 26451 6011)

#include "TextureCube.h"
#include "Error.h"

namespace Minecraft { namespace API {

	TextureCube::TextureCube() {

		Init();
	}

	TextureCube::TextureCube(const eastl::vector<eastl::string>& filenames) {

		Init();
		LoadTexture(filenames);
	}

	TextureCube::~TextureCube() {

		GLCall(glDeleteTextures(1, &m_TextureID))
	}

	void TextureCube::Bind(GLuint slot) const {

		GLCall(glActiveTexture(GL_TEXTURE0 + slot))
		GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, m_TextureID))
	}

	void TextureCube::UnBind() const {

		GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, m_TextureID))
	}

	void TextureCube::Init() {

		GLCall(glGenTextures(1, &m_TextureID))
		GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, m_TextureID))

		GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE))
		GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE))
		GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE))
		GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR))
		GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR))

		GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, GL_ZERO))
	}

	bool TextureCube::LoadTexture(const eastl::vector<eastl::string>& filenames) {

		int width, height, channels;

		GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, m_TextureID))

		for (size_t i = 0; i < filenames.size(); i++) {

			byte* image = (byte*)stbi_load(filenames[i].c_str(), &width, &height, &channels, 0);

			if (!image) {

				std::cout << "Failed to load texture: " << filenames[i].c_str()
					<< "\nReason: " << stbi_failure_reason() << std::endl;
				return false;
			}

			int internalFormat;
			int dataFormat;

			if (channels == 4) {

				internalFormat = GL_RGBA8;
				dataFormat = GL_RGBA;
			}
			else if (channels == 3) {

				internalFormat = GL_RGB8;
				dataFormat = GL_RGB;
			}
			else {

				std::cout << "Unsupported Texture: " << filenames[i].c_str() << std::endl;
				return false;
			}

			GLCall(glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + (GLenum)i, GL_ZERO, internalFormat, width, height, GL_ZERO, dataFormat, GL_UNSIGNED_BYTE, image))
			stbi_image_free(image);
		}

		GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, GL_ZERO))

		return true;
	}
} }