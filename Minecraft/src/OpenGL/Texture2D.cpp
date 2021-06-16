#include <MC.h>

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#pragma warning(disable : 26451 6011)
#include <STBImage.h>
#pragma warning(default : 26451 6011)

#include "Texture2D.h"
#include "Error.h"

namespace Minecraft { namespace API {

	Texture2D::Texture2D()
		: m_Width(0), m_Height(0), m_Channels(0) {

		Init();
	}

	Texture2D::Texture2D(const eastl::string& filename) {

		Init();
		LoadTexture(filename);
	}

	Texture2D::~Texture2D() {

		GLCall(glDeleteTextures(1, &m_TextureID))
	}

	void Texture2D::Bind(GLuint slot) const {

		GLCall(glActiveTexture(GL_TEXTURE0 + slot))
		GLCall(glBindTexture(GL_TEXTURE_2D, m_TextureID))
	}

	void Texture2D::UnBind() const {

		GLCall(glBindTexture(GL_TEXTURE_2D, m_TextureID))
	}

	void Texture2D::Init() {

		GLCall(glGenTextures(1, &m_TextureID))
		GLCall(glBindTexture(GL_TEXTURE_2D, m_TextureID))

		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT))
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT))
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST))
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST))

		GLCall(glBindTexture(GL_TEXTURE_2D, GL_ZERO))
	}

	bool Texture2D::LoadTexture(const eastl::string& filename) {

		byte* image;

		stbi_set_flip_vertically_on_load(true);

		image = (byte*)stbi_load(filename.c_str(), (int*)(&m_Width), (int*)(&m_Height), (int*)(&m_Channels), 0);

		if (!image) {

			std::cout << "Failed to load texture: " << filename.c_str()
				<< "\nReason: " << stbi_failure_reason() << std::endl;
			return false;
		}

		int internalFormat;
		int dataFormat;

		if (m_Channels == 4) {

			internalFormat = GL_RGBA8;
			dataFormat = GL_RGBA;
		}
		else if (m_Channels == 3) {

			internalFormat = GL_RGB8;
			dataFormat = GL_RGB;
		}
		else {

			std::cout << "Unsupported Texture: " << filename.c_str() << std::endl;
			return false;
		}

		GLCall(glBindTexture(GL_TEXTURE_2D, m_TextureID))
		GLCall(glTexImage2D(GL_TEXTURE_2D, GL_ZERO, internalFormat, m_Width, m_Height, GL_ZERO, dataFormat, GL_UNSIGNED_BYTE, image))
		GLCall(glGenerateMipmap(GL_TEXTURE_2D))
		GLCall(glBindTexture(GL_TEXTURE_2D, GL_ZERO))

		stbi_image_free(image);
		return true;
	}
} }