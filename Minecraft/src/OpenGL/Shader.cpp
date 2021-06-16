#include <MC.h>

#include <iostream>

#include "Error.h"
#include "Shader.h"
#include "Utilities/FileSystem.h"

namespace Minecraft { namespace API {

	Shader::Shader(const eastl::vector<eastl::string>& shaderPaths) {

		Init(shaderPaths);
	}

	Shader::~Shader() {

		GLCall(glDeleteProgram(m_RendererID))
	}

	void Shader::Bind() const {

		GLCall(glUseProgram(m_RendererID))
	}
	
	void Shader::UnBind() const {

		GLCall(glUseProgram(GL_ZERO))
	}

	void Shader::SetUniformInt(const eastl::string& name, int value) {

		GLint location;

		if (m_UniformCache.find(name) != m_UniformCache.end())
			location = m_UniformCache[name];
		else {
			
			GLCall(location = glGetUniformLocation(m_RendererID, name.c_str()))
			m_UniformCache[name] = location;
		}
		GLCall(glUniform1i(location, value))
	}

	void Shader::SetUniformFloat(const eastl::string& name, float value) {

		GLint location;

		if (m_UniformCache.find(name) != m_UniformCache.end())
			location = m_UniformCache[name];
		else {

			GLCall(location = glGetUniformLocation(m_RendererID, name.c_str()))
			m_UniformCache[name] = location;
		}
		GLCall(glUniform1f(location, value))
	}

	void Shader::SetUniformVec2f(const eastl::string& name, const glm::vec2& value) {

		GLint location;

		if (m_UniformCache.find(name) != m_UniformCache.end())
			location = m_UniformCache[name];
		else {

			GLCall(location = glGetUniformLocation(m_RendererID, name.c_str()))
			m_UniformCache[name] = location;
		}
		GLCall(glUniform2f(location, value.x, value.y))
	}

	void Shader::SetUniformVec3f(const eastl::string& name, const glm::vec3& value) {

		GLint location;

		if (m_UniformCache.find(name) != m_UniformCache.end())
			location = m_UniformCache[name];
		else {

			GLCall(location = glGetUniformLocation(m_RendererID, name.c_str()))
			m_UniformCache[name] = location;
		}
		GLCall(glUniform3f(location, value.x, value.y, value.z))
	}

	void Shader::SetUniformVec4f(const eastl::string& name, const glm::vec4& value) {

		GLint location;

		if (m_UniformCache.find(name) != m_UniformCache.end())
			location = m_UniformCache[name];
		else {

			GLCall(location = glGetUniformLocation(m_RendererID, name.c_str()))
			m_UniformCache[name] = location;
		}
		GLCall(glUniform4f(location, value.x, value.y, value.z, value.w))
	}

	void Shader::SetUniformMat3f(const eastl::string& name, const glm::mat3& value) {

		GLint location;

		if (m_UniformCache.find(name) != m_UniformCache.end())
			location = m_UniformCache[name];
		else {

			GLCall(location = glGetUniformLocation(m_RendererID, name.c_str()))
			m_UniformCache[name] = location;
		}
		GLCall(glUniformMatrix3fv(location, 1, false, &value[0][0]))
	}

	void Shader::SetUniformMat4f(const eastl::string& name, const glm::mat4& value) {

		GLint location;

		if (m_UniformCache.find(name) != m_UniformCache.end())
			location = m_UniformCache[name];
		else {

			GLCall(location = glGetUniformLocation(m_RendererID, name.c_str()))
			m_UniformCache[name] = location;
		}
		GLCall(glUniformMatrix4fv(location, 1, false, &value[0][0]))
	}

	void Shader::Init(const eastl::vector<eastl::string>& shaderPaths) {

		GLCall(m_RendererID = glCreateProgram())

		eastl::vector<GLuint> shaderID;

		for (size_t i = 0; i < shaderPaths.size(); i++) {

			ShaderData shaderData = FileSystem::ReadShaderFile(shaderPaths[i]);

			GLuint id;
			GLCall(id = glCreateShader(GLShaderType(shaderData.shaderType)))

			shaderID.push_back(id);

			const char* source = shaderData.source.c_str();

			GLCall(glShaderSource(id, 1, &source, GL_ZERO))
			GLCall(glCompileShader(id))

			int result;
			char info[512];

			GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result))

			if (result == GL_FALSE) {

				GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &result))
				GLCall(glGetShaderInfoLog(id, 512, GL_ZERO, info))

				std::cout << "Shader: " << ShaderTypeToString(shaderData.shaderType).c_str()
						<< "\nInfo: " << info << "\nFile: " << shaderPaths[i].c_str() << std::endl;
			}

			GLCall(glAttachShader(m_RendererID, id))
		}

		GLCall(glLinkProgram(m_RendererID))

		int result;
		char info[512];

		GLCall(glGetProgramiv(m_RendererID, GL_LINK_STATUS, &result))

		if (result == GL_FALSE) {

			GLCall(glGetProgramiv(m_RendererID, GL_INFO_LOG_LENGTH, &result))
			GLCall(glGetProgramInfoLog(m_RendererID, 512, GL_ZERO, info))

			std::cout << "Link Status, Failed, : " << info << std::endl;
		}

		for (size_t i = 0; i < shaderID.size(); i++) {

			auto id = shaderID[i];
			GLCall(glDetachShader(m_RendererID, id))
		}
	}
} }