#pragma once

#include <MC.h>

namespace Minecraft { namespace API {

	class Shader {

	public:
		enum class ShaderType {
			UNKNOWN = 0,
			VERTEX,
			FRAGMENT
		}; // we gonna support only 2 shaders for now

	private:
		GLuint m_RendererID;
		eastl::hash_map<eastl::string, GLuint>m_UniformCache;

	public:
		Shader() = delete;
		Shader(const eastl::vector<eastl::string>& shaderPaths);
		~Shader();

		void Bind() const;
		void UnBind() const;

		void SetUniformInt(const eastl::string& name, int value);
		void SetUniformFloat(const eastl::string& name, float value);
		void SetUniformVec2f(const eastl::string& name, const glm::vec2& value);
		void SetUniformVec3f(const eastl::string& name, const glm::vec3& value);
		void SetUniformVec4f(const eastl::string& name, const glm::vec4& value);
		void SetUniformMat3f(const eastl::string& name, const glm::mat3& value);
		void SetUniformMat4f(const eastl::string& name, const glm::mat4& value);

	private:
		void Init(const eastl::vector<eastl::string>& shaderPaths);

		inline GLenum GLShaderType(ShaderType shaderType) {

			switch (shaderType) {

				case ShaderType::VERTEX:
					return GL_VERTEX_SHADER;
				case ShaderType::FRAGMENT:
					return GL_FRAGMENT_SHADER;
				default:
					return GL_ZERO;
			}
		}

		inline eastl::string ShaderTypeToString(ShaderType shaderType) {

			switch (shaderType) {

				case ShaderType::VERTEX:
					return "GL_VERTEX_SHADER";
				case ShaderType::FRAGMENT:
					return "GL_FRAGMENT_SHADER";
				default:
					return "UNKNOWN_SHADER";
			}
		}
	};
} }