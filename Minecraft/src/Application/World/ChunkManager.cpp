#include <MC.h>

#include "WorldConfig.h"
#include "ChunkManager.h"
#include "BlockDataManager.h"

namespace Minecraft {

	ChunkManager* ChunkManager::s_Instance = nullptr;

	void ChunkManager::Init() { 
	
		BlockDataManager::Create()->Init();

		m_Chunks.resize(WORLD_LENGTH * WORLD_WIDTH);

		size_t index = 0;

		for (uint wL = 0; wL < WORLD_LENGTH; wL++)
			for (uint wW = 0; wW < WORLD_WIDTH; wW++)
				m_Chunks[index++].SetPosition(glm::uvec3(wW * CHUNK_WIDTH, 0, wL * CHUNK_LENGTH));
	}

	void ChunkManager::ShutDown() {

		BlockDataManager::GetInstance()->ShutDown();
		delete s_Instance;
	}


	void ChunkManager::AddBlock(BlockType type, const glm::uvec3& position) {

		uint chunkX = position.x / CHUNK_WIDTH;
		uint chunkY = position.y;
		uint chunkZ = position.z / CHUNK_LENGTH;

		uint X = position.x % CHUNK_WIDTH;
		uint Y = position.y;
		uint Z = position.z % CHUNK_LENGTH;

		size_t index = ((size_t)chunkZ * WORLD_WIDTH) + (size_t)chunkX;

		if (index < 0 || index >= WORLD_LENGTH * WORLD_WIDTH)
			return;

		m_Chunks[index].SetBlock(type, glm::uvec3(X, Y, Z));

	}

	BlockType ChunkManager::GetBlockType(const glm::uvec3& position) const {

		uint chunkX = position.x / CHUNK_WIDTH;
		uint chunkY = position.y;
		uint chunkZ = position.z / CHUNK_LENGTH;

		uint X = position.x % CHUNK_WIDTH;
		uint Y = position.y;
		uint Z = position.z % CHUNK_LENGTH;

		size_t index = ((size_t)chunkZ * WORLD_WIDTH) + (size_t)chunkX;

		if (index < 0 || index >= WORLD_LENGTH * WORLD_WIDTH)
			return BlockType::Invalid;

		return m_Chunks[index].GetBlockType(glm::uvec3(X, Y, Z));
	}

	void ChunkManager::Render(bool render, const glm::uvec3& position) {

		uint chunkX = position.x / CHUNK_WIDTH;
		uint chunkY = position.y;
		uint chunkZ = position.z / CHUNK_LENGTH;

		uint X = position.x % CHUNK_WIDTH;
		uint Y = position.y;
		uint Z = position.z % CHUNK_LENGTH;

		size_t index = ((size_t)chunkZ * WORLD_WIDTH) + (size_t)chunkX;

		if (index < 0 || index >= WORLD_LENGTH * WORLD_WIDTH)
			return;

		m_Chunks[index].Render(render, glm::uvec3(X, Y, Z));
	}


	void ChunkManager::LoadChunks() {

		for(auto& chunk : m_Chunks)
			chunk.LoadChunk();
	}

	void ChunkManager::Render() const {

		for (auto& chunk : m_Chunks)
			API::RenderCommand::DrawIndexed(chunk.GetVertexArray());
	}
}