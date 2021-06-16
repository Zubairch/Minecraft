#pragma once

#include "Block.h"
#include "BlockData.h"

namespace Minecraft {

	class BlockDataManager {

	private:
		static BlockDataManager* s_Instance;

	private:
		eastl::vector<BlockData> m_BlockData;

	public:
		BlockDataManager() = default;
		~BlockDataManager() = default;

		void Init();
		void ShutDown();

		inline const BlockData& GetBlockData(BlockType type) { return m_BlockData[(size_t)type]; }

		inline static BlockDataManager* Create() { return s_Instance = new BlockDataManager();  }
		inline static BlockDataManager* GetInstance() { return s_Instance; }
	};
}