#pragma once

#include <MC.h> 

#include "WorldConfig.h"

#include "OpenGL/Texture2D.h"

namespace Minecraft {

	class BlockData {

	private:
		static constexpr GLfloat s_VertexData[] = {
			// Vertices           
			// front face
			 -BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE,
			 -BLOCK_SIZE,  BLOCK_SIZE, BLOCK_SIZE,
			  BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE,
			  BLOCK_SIZE,  BLOCK_SIZE, BLOCK_SIZE,

			// back face
			  BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE,
			  BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE,
			 -BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE,
			 -BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE,

			// left face
			 -BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE,
			 -BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE,
			 -BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE,
			 -BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE,

			// right face
			  BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE,
			  BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE,
			  BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE,
			  BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE,

			// top face
			 -BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE,
			 -BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE,
			  BLOCK_SIZE,  BLOCK_SIZE,  BLOCK_SIZE,
			  BLOCK_SIZE,  BLOCK_SIZE, -BLOCK_SIZE,

			// bottom face
			 -BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE,
			 -BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE,
			  BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE,
			  BLOCK_SIZE, -BLOCK_SIZE,  BLOCK_SIZE
		};

	private:
		eastl::vector<GLfloat> m_VertexData;

	public:
		BlockData();
		BlockData(const API::Texture2D& texture, const eastl::string& filename);
		~BlockData() = default;

		void CalculateVertexData(const API::Texture2D& texture, const eastl::string& filename);

		const eastl::vector<GLfloat>& GetVertexData() const { return m_VertexData; }

	private:
		void Init();
		
		struct AtlasData {

			uint size;
			uint top;
			uint down;
			uint side;

			AtlasData() = default;
			AtlasData(const AtlasData& data) = default;
		};

		AtlasData LoadAtlasData(const eastl::string& filename) const;
	};
}


