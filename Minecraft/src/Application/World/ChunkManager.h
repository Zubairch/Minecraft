#pragma once

#include <MC.h>

#include "Chunk.h"

namespace Minecraft {

	class ChunkManager {

	private:
		static ChunkManager* s_Instance;

	private:
		eastl::vector<Chunk> m_Chunks;

	public:
		ChunkManager() = default;
		~ChunkManager() = default;
		
		void Init();
		void ShutDown();

		void AddBlock(BlockType type, const glm::uvec3& position);

		BlockType GetBlockType(const glm::uvec3& position) const;

		void ChunkManager::Render(bool render, const glm::uvec3& position);

		void LoadChunks();
		void Render() const;

		inline static ChunkManager* Create() { return s_Instance = new ChunkManager(); }
		inline static ChunkManager* GetInstance() { return s_Instance; }
	};
}
