#pragma once

#define CHUNKSIZE 80

class Chunk
{
public:
	Chunk();
	~Chunk();

private:
	char ch[CHUNKSIZE];
	Chunk* next;
};

Chunk::Chunk()
{
}

Chunk::~Chunk()
{
}