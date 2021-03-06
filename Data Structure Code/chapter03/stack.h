#pragma once
#include <iostream>

using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

template <class T>
class SqStack
{
public:
	SqStack()
	{
		this->base = new T[MAXSIZE];
		if (!this->base)
		{
			exit(OVERFLOW);
		}
		this->top = this->base;
		this->stacksize = MAXSIZE;
	}
	~SqStack()
	{

	}
	Status Push(T e)
	{
		if (this->top - this->base == this->stacksize)
		{
			return ERROR;
		}
		*this->top++ = e;
		return OK;
	}
	Status Pop(T& e)
	{
		if (this->top == this->base)
		{
			return ERROR;
		}
		e = *--this->top;
		return OK;
	}
	T GetTop()
	{
		if (this->top != this->base)
		{
			return *(this->top - 1);
		}
	}
	Status StackEmpty()
	{
		if (this->top == this->base)
		{
			return OK;
		}
		else
		{
			return ERROR;
		}
	}


private:
	T* base;
	T* top;
	int stacksize;
};