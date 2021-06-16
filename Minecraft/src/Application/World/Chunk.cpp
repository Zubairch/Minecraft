#include <MC.h>

#include "Chunk.h"


namespace Minecraft {

	Chunk::Chunk()
		: m_Blocks(CHUNK_SIZE, Block(BlockType::Air, false)), m_Count(0) { }

	void Chunk::SetBlock(BlockType type, const glm::uvec3& position) {

		uint16 index = (uint16)((position.y * CHUNK_LENGTH + position.z) * CHUNK_WIDTH + position.x);

		if (index >= CHUNK_SIZE || index < 0)
			return;
		
		m_Blocks[index].SetBlockType(type);

		m_Count++;
	}

	Block Chunk::GetBlock(const glm::uvec3& position) const {

		uint16 index = (uint16)((position.y * CHUNK_LENGTH + position.z) * CHUNK_WIDTH + position.x);

		if (index >= CHUNK_SIZE || index < 0)
			return Block(BlockType::Invalid, false);
		return m_Blocks[index];
	}

	void Chunk::Render(bool render, const glm::uvec3& position) {

		uint16 index = (uint16)((position.y * CHUNK_LENGTH + position.z) * CHUNK_WIDTH + position.x);

		if (index >= CHUNK_SIZE || index < 0)
			return;
		m_Blocks[index].Render(render);
	}

	bool Chunk::IsRendered(const glm::uvec3& position) const {

		uint16 index = (uint16)((position.y * CHUNK_LENGTH + position.z) * CHUNK_WIDTH + position.x);

		if (index >= CHUNK_SIZE || index < 0)
			return false;
		return m_Blocks[index].IsRendered();
	}

	BlockType Chunk::GetBlockType(const glm::uvec3& position) const {

		uint16 index = (uint16)((position.y * CHUNK_LENGTH + position.z) * CHUNK_WIDTH + position.x);

		if (index >= CHUNK_SIZE || index < 0)
			return BlockType::Invalid;
		return m_Blocks[index].GetBlockType();
	}

	void Chunk::LoadChunk() {

		constexpr auto vertexSize = 120;
		size_t count = 0;

		eastl::vector<GLfloat> data;
		data.reserve(3 * m_Count * vertexSize);

		for (uint y = 0; y < CHUNK_DEPTH; y++)
			for (uint z = 0; z < CHUNK_LENGTH; z++)
				for (uint x = 0; x < CHUNK_WIDTH; x++)
					if (IsRendered(glm::uvec3(x, y, z))) {

						glm::uvec3 pos(x, y, z);
						BlockType type = GetBlockType(pos);
						
						auto vertex = BlockDataManager::GetInstance()->GetBlockData(type).GetVertexData();

						for (size_t j = 0; j < vertexSize; j += 5) {

							GLfloat X = vertex[j + 0] + (GLfloat)pos.x + m_Position.x;
							GLfloat Y = vertex[j + 1] + (GLfloat)pos.y + m_Position.y;
							GLfloat Z = vertex[j + 2] + (GLfloat)pos.z + m_Position.z;
							GLfloat Tx = vertex[j + 3];
							GLfloat Ty = vertex[j + 4];

							data.push_back(X);
							data.push_back(Y);
							data.push_back(Z);
							data.push_back(Tx);
							data.push_back(Ty);
						}

						count++;
					}
					
		eastl::vector<GLuint> indexData;
		indexData.reserve(3 * count * 36);

		uint offset = 0;

		for (size_t i = 0; i < indexData.capacity(); i += 6) {

			indexData.push_back(offset + 0);
			indexData.push_back(offset + 1);
			indexData.push_back(offset + 2);

			indexData.push_back(offset + 2);
			indexData.push_back(offset + 1);
			indexData.push_back(offset + 3);

			offset += 4;
		}

		API::VertexBuffer* vertexBuffer = new API::VertexBuffer(API::VertexBuffer::BufferUsage::STATIC);
		API::IndexBuffer* indexBuffer = new API::IndexBuffer();

		API::BufferLayout layout;
		layout.Push(3, 3, false);
		layout.Push(2, 3, false);

		indexBuffer->SetIndexData(indexData);

		vertexBuffer->SetVertexData(data);
		vertexBuffer->SetBufferLayout(layout);

		m_VertexArray.PushBuffer(vertexBuffer);
		m_VertexArray.PushBuffer(indexBuffer);

	}
}
