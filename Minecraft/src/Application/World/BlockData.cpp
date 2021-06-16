#include <MC.h>

#include "BlockData.h"

namespace Minecraft {

	BlockData::BlockData() {
			
		Init();
	}

	BlockData::BlockData(const API::Texture2D& texture, const eastl::string& filename) {

		Init();
		CalculateVertexData(texture, filename);
	}

	void BlockData::CalculateVertexData(const API::Texture2D& texture, const eastl::string& filename) {

		auto data = LoadAtlasData(filename);

		uint width = texture.GetWidth();
		uint height = texture.GetHeight();

		glm::vec2 top[2];
		glm::vec2 down[2];
		glm::vec2 side[2];

		uint rows = width / data.size; // assuming that Atlas size is NxN and texture size if data.size

		float size = (float)data.size / width;

		uint xOffset = data.top % rows;
		uint yOffset = data.top / rows;

		top[0].x = (float)xOffset * size;
		top[0].y = (float)yOffset * size;

		top[1].x = (float)(xOffset + 1.0f) * size;
		top[1].y = (float)(yOffset + 1.0f) * size;

		xOffset = data.down % rows;
		yOffset = data.down / rows;

		down[0].x = (float)xOffset * size;
		down[0].y = (float)yOffset * size;

		down[1].x = (float)(xOffset + 1.0f) * size;
		down[1].y = (float)(yOffset + 1.0f) * size;

		xOffset = data.side % rows;
		yOffset = data.side / rows;

		side[0].x = (float)xOffset * size;
		side[0].y = (float)yOffset * size;

		side[1].x = (float)(xOffset + 1.0f) * size;
		side[1].y = (float)(yOffset + 1.0f) * size;

		//std::cout << "File:   " << filename.c_str() << std::endl;
		//std::cout << "Height: " << height << ", Width: " << width << std::endl;
		//std::cout << "Size:   " << data.size << std::endl;

		//std::cout << "Top Index:  " << data.top << std::endl;
		//std::cout << "Down Index: " << data.down << std::endl;
		//std::cout << "Side Index: " << data.side << std::endl;

		//std::cout << "TOP:  " << top[0].x << ", " << top[0].y << " -> " << top[1].x << ", " << top[1].y << std::endl;
		//std::cout << "DOWN: " << down[0].x << ", " << down[0].y << " -> " << top[1].x << ", " << down[1].y << std::endl;
		//std::cout << "SIDE: " << side[0].x << ", " << side[0].y << " -> " << side[1].x << ", " << side[1].y << std::endl << std::endl;


		m_VertexData = {
			// Vertices              Texture Coordinates
			// front face
			 -BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE, side[0].x, side[0].y,
			 -BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE, side[0].x, side[1].y,
			  BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE, side[1].x, side[0].y,
			  BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE, side[1].x, side[1].y,

			// back face
			  BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE, side[1].x, side[0].y,
			  BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE, side[1].x, side[1].y,
			 -BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE, side[0].x, side[0].y,
			 -BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE, side[0].x, side[1].y,

			// left face
			 -BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE, side[0].x, side[0].y,
			 -BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE, side[0].x, side[1].y,
			 -BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE, side[1].x, side[0].y,
			 -BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE, side[1].x, side[1].y,

			// right face
			  BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE, side[0].x, side[0].y,
			  BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE, side[1].x, side[0].y,
			  BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE, side[0].x, side[1].y,
			  BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE, side[1].x, side[1].y,

			// top face
			 -BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE, top[1].x, top[0].y,
			 -BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE, top[0].x, top[0].y,
			  BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE, top[1].x, top[1].y,
			  BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE, top[0].x, top[1].y,

			// bottom face
			 -BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE, down[0].x, down[0].y,
			 -BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE, down[1].x, down[0].y,
			  BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE, down[0].x, down[1].y,
			  BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE, down[1].x, down[1].y,
		};
	}

	void BlockData::Init() {

		m_VertexData = {
			// Vertices              Texture Coordinates
			// front face
			 -BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE, 0.0f, 0.0f,
			 -BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE, 0.0f, 1.0f,
			  BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE, 1.0f, 0.0f,
			  BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE, 1.0f, 1.0f,

			// back face
			  BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE, 1.0f, 0.0f,
			  BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE, 1.0f, 1.0f,
			 -BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE, 0.0f, 0.0f,
			 -BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE, 0.0f, 1.0f,

			// left face
			 -BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE, 0.0f, 0.0f,
			 -BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE, 0.0f, 1.0f,
			 -BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE, 1.0f, 0.0f,
			 -BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE, 1.0f, 1.0f,

			// right face
			  BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE, 0.0f, 0.0f,
			  BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE, 1.0f, 0.0f,
			  BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE, 0.0f, 1.0f,
			  BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE, 1.0f, 1.0f,

			// top face
			 -BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE, 1.0f, 0.0f,
			 -BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE, 0.0f, 0.0f,
			  BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE, 1.0f, 1.0f,
			  BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE, 0.0f, 1.0f,

			// bottom face
			 -BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE, 0.0f, 0.0f,
			 -BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE, 1.0f, 0.0f,
			  BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE, 0.0f, 1.0f,
			  BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE, 1.0f, 1.0f,
		};
	}

	BlockData::AtlasData BlockData::LoadAtlasData(const eastl::string& filename) const {

		std::ifstream fin(filename.c_str());

		if (!fin) {

			std::cout << "Can't Open File: " << filename.c_str() << std::endl;
			return AtlasData();
		}

		AtlasData data;

		fin >> data.size;
		fin >> data.top;
		fin >> data.down;
		fin >> data.side;

		fin.close();

		return data;
	}
}
