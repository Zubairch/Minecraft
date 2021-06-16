#include <MC.h>

#include "Block.h"

namespace Minecraft {

	Block::Block()
		: m_Type(BlockType::Air), m_Rendered(false) { }

	Block::Block(BlockType type, bool render)
		: m_Type(type), m_Rendered(render) { }

}