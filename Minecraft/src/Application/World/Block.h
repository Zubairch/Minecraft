#pragma once

#include <MC.h>

namespace Minecraft {

	enum class BlockType : uint8 {

		Air = 0,

		Dirt,
		Grass,
		Stone,
		Sand,
		Snow,
		//Water,

		NumTypes,

		Invalid,
	};

	class Block {

	private:
		BlockType m_Type;
		bool m_Rendered;

	public:
		Block();
		Block(BlockType type, bool render);
		~Block() = default;

		inline BlockType GetBlockType() const { return m_Type; };
		inline void SetBlockType(BlockType type) { m_Type = type; };

		inline bool IsRendered() const { return m_Rendered; }
		inline void Render(bool render) { m_Rendered = render; }
	};
}
