#pragma once

#include "ChunkManager.h"

namespace Minecraft {

	static noise::module::Perlin s_PerlinNoise;

	class World {

	public:
		World() = default;
		~World() = default;

		void Init();
		void Update(float dt);

	//	void ShutDown();
	private:
		BlockType GetBiome(uint height) const;
	};
}