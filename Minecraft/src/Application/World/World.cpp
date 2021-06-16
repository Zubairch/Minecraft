#include <MC.h>

#include "World.h"

namespace Minecraft {

	inline static uint GetHeight(uint x, uint z) {

		double scale = 0.00834;

		double value = s_PerlinNoise.GetValue((double)x * scale, 0.5, (double)z * scale);

		return (uint)Abs((int)Map(value, -1.0, 1.0, 0.0, (double)CHUNK_DEPTH - 1.0f));
	}

	void World::Init() {

		ChunkManager::Create()->Init();
	
		for(uint wL = 0; wL < WORLD_LENGTH * CHUNK_LENGTH; wL++)
			for (uint wW = 0; wW < WORLD_WIDTH * CHUNK_WIDTH; wW++) {
			
				uint height = GetHeight(wW, wL);
			
				for (uint y = 0; y <= height; y++)
					ChunkManager::GetInstance()->AddBlock(GetBiome(y), glm::uvec3(wW, y, wL));
			}

		for(uint y = 0; y < CHUNK_DEPTH; y++)
			for (uint wL = 0; wL < WORLD_LENGTH * CHUNK_LENGTH; wL++)
				for (uint wW = 0; wW < WORLD_WIDTH * CHUNK_WIDTH; wW++) {
					
					if (ChunkManager::GetInstance()->GetBlockType(glm::uvec3(wW, y, wL)) != BlockType::Air) {

						bool answer = false;

						if (ChunkManager::GetInstance()->GetBlockType(glm::uvec3(wW + 1, y, wL)) == BlockType::Air)
							answer = true;
						else if (ChunkManager::GetInstance()->GetBlockType(glm::uvec3(wW - 1, y, wL)) == BlockType::Air)
							answer = true;
						else if (ChunkManager::GetInstance()->GetBlockType(glm::uvec3(wW, y + 1, wL)) == BlockType::Air)
							answer = true;
						else if (ChunkManager::GetInstance()->GetBlockType(glm::uvec3(wW, y - 1, wL)) == BlockType::Air)
							answer = true;
						else if (ChunkManager::GetInstance()->GetBlockType(glm::uvec3(wW, y, wL + 1)) == BlockType::Air)
							answer = true;
						else if (ChunkManager::GetInstance()->GetBlockType(glm::uvec3(wW, y, wL - 1)) == BlockType::Air)
							answer = true;

						if (answer)
							ChunkManager::GetInstance()->Render(true, glm::uvec3(wW, y, wL));
					}
				}

		ChunkManager::GetInstance()->LoadChunks();
	}

	void World::Update(float dt) {

		ChunkManager::GetInstance()->Render();
	}

	BlockType World::GetBiome(uint height) const {
	
		if (height < 20)
			return BlockType::Stone;
		if (height < 30)
			return BlockType::Sand;
		if (height < 50)
			return BlockType::Grass;
		return BlockType::Snow;
	}
}