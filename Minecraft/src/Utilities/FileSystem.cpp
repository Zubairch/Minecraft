#include <MC.h>

#include "FileSystem.h"
#include <iostream>

namespace Minecraft {

	ShaderData FileSystem::ReadShaderFile(eastl::string filename) {

		FILE* file;

		fopen_s(&file, filename.c_str(), "rb");

		if (!file) {

			std::cout << "File: " << filename.c_str() << " not found!" << std::endl;
			return ShaderData();
		}

		ShaderData data;

		fseek(file, 0, SEEK_END);
		uint length = ftell(file);

		data.source.resize(length, NULL);

		fseek(file, 0, SEEK_SET);
		fread(&data.source[0], 1, length, file);
		fclose(file);

		size_t i = 0;
		while (data.source[i] != '\n' && data.source[i] != '\0' && data.source[i] != '\r')
			i++;

		eastl::string type;

		for (size_t j = 0; j < i; j++)
			type.push_back(data.source[j]);

		if (type.compare("#Vertex Shader") == 0)
			data.shaderType = API::Shader::ShaderType::VERTEX;
		else if (type.compare("#Fragment Shader") == 0)
			data.shaderType = API::Shader::ShaderType::FRAGMENT;
		else
			data.shaderType = API::Shader::ShaderType::UNKNOWN;
		
		data.source = eastl::string(&data.source[i + 1]);
		data.source.erase(eastl::remove(data.source.begin(), data.source.end(), '\r'), data.source.end());

		return data;
	}
}