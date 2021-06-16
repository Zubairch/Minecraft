#pragma once

#include <MC.h>

namespace Minecraft { namespace API {

	class Texture2D {

	private:
		GLuint m_TextureID;
		GLuint m_Width;
		GLuint m_Height;
		GLuint m_Channels;

	public:
		Texture2D();
		Texture2D(const eastl::string& filename);
		~Texture2D();

		void Bind(GLuint slot = 0) const;
		void UnBind() const;

		bool LoadTexture(const eastl::string& filename);

		GLuint GetWidth() const { return m_Width; }
		GLuint GetHeight() const { return m_Height; }
		GLuint GetChannels() const { return m_Channels; }

	private:
		void Init();
	};
} }
