#include <MC.h>

#include "BlockDataManager.h"

namespace Minecraft {

	BlockDataManager* BlockDataManager::s_Instance = nullptr;

	void BlockDataManager::Init() {

		m_BlockData.resize((size_t)BlockType::NumTypes);

		eastl::vector<eastl::string> files = {

			"../Resources/BlockTypes/Air.txt",
			"../Resources/BlockTypes/Dirt.txt",
			"../Resources/BlockTypes/Grass.txt",
			"../Resources/BlockTypes/Stone.txt",
			"../Resources/BlockTypes/Sand.txt",
			"../Resources/BlockTypes/Snow.txt"
		};
		// TODO: Texture Manager
		API::Texture2D texture("../Resources/Textures/Atlas.png");

		for (size_t i = 0; i < (size_t)BlockType::NumTypes; i++)
			m_BlockData[i].CalculateVertexData(texture, files[i]);
	}

	void BlockDataManager::ShutDown() { 
	
		delete s_Instance;
	}
}