#pragma once

static constexpr size_t CHUNK_WIDTH =			16; // x axis BLOCKS
static constexpr size_t CHUNK_DEPTH =			64; // y axis BLOCKS
static constexpr size_t CHUNK_LENGTH =			16; // z axis BLOCKS

static constexpr size_t INDICIES_PER_BLOCK =	36; // 6 Faces each with 6 verticies

static constexpr float BLOCK_SIZE =			0.5f;

static constexpr size_t CHUNK_SIZE	=			(CHUNK_WIDTH * CHUNK_DEPTH * CHUNK_LENGTH);
static constexpr size_t CHUNK_INDICIES_SIZE	=	(CHUNK_SIZE * INDICIES_PER_BLOCK);

static constexpr size_t WORLD_LENGTH =			20; // CHUNKS
static constexpr size_t WORLD_WIDTH	=			20;//  
