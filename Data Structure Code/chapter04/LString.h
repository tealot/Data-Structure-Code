#pragma once

#include <iostream>
#include "Chunk.h"
#define MAXSIZE 100
#define MAXLEN 255
#define OK 1
#define ERROR 0
#define OVERFLOW -2

class LString
{
public:
	LString();
	~LString();

private:
	Chunk* head;
	Chunk* tail;
	int length;
};

LString::LString()
{
}

LString::~LString()
{
}