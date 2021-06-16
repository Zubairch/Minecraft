#pragma once

#include <MC.h>

#include "OpenGL/Shader.h"

namespace Minecraft {

	struct ShaderData {

	public:
		eastl::string source;
		API::Shader::ShaderType shaderType;

	public:
		ShaderData()
			: shaderType(API::Shader::ShaderType::UNKNOWN) { }

		ShaderData(eastl::string shaderSource, API::Shader::ShaderType type)
			: source(shaderSource), shaderType(type) { }

		ShaderData(const ShaderData& data)
			: source(data.source), shaderType(data.shaderType) { }
	};

	class FileSystem {

	public:
		FileSystem() = delete;
		~FileSystem() = delete;

		static ShaderData ReadShaderFile(eastl::string filename);
	};
}
