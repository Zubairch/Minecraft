#pragma once

#include <MC.h>
#include <noise/module/perlin.h>

#include "WorldConfig.h"

#include "Block.h"
#include "BlockDataManager.h"

#include "OpenGL/VertexArray.h"
#include "OpenGL/RenderCommand.h"

namespace Minecraft {

	class Chunk {

	private:
		glm::uvec3 m_Position;
		eastl::vector<Block> m_Blocks;
		API::VertexArray m_VertexArray;
		size_t m_Count;

	public:
		Chunk();
		~Chunk() = default;

		inline void SetPosition(const glm::uvec3& position) { m_Position = position; }
		inline const glm::uvec3& GetPosition() const { return m_Position; }

		void LoadChunk();

		void SetBlock(BlockType type, const glm::uvec3& position);
		Block GetBlock(const glm::uvec3& position) const;

		void Render(bool render, const glm::uvec3& position);
		bool IsRendered(const glm::uvec3& position) const;

		BlockType GetBlockType(const glm::uvec3& position) const;

		inline const API::VertexArray& GetVertexArray() const { return m_VertexArray; }
	};
}
