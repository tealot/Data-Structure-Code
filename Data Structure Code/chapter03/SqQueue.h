#pragma once
#include <iostream>

using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

template <class T>
class SqQueue
{
public:
	SqQueue()
	{
		this->base = new T[MAXSIZE];
		if (!this->base)
		{
			exit(OVERFLOW);
		}
		this->front = this->rear = 0;
	}
	~SqQueue();
	int QueueLength()
	{
		return (this->rear - this->front + MAXSIZE) % MAXSIZE;
	}
	Status EnQueue(T e)
	{
		if ((this->rear + 1) % MAXSIZE == this->front)
		{
			return ERROR;
		}
		this->base[this->rear] = e;
		this->rear = (this->rear + 1) % MAXSIZE;
		return OK;
	}
	Status DeQueue(T& e)
	{
		if (this->front == this->rear)
		{
			return ERROR;
		}
		e = this->base[this->front];
		this->front = (this->front + 1) % MAXSIZE;
		return OK;
	}
	T GetHead()
	{
		if (this->front != this->rear)
		{
			return this->base[this->front];
		}
	}
private:
	T* base;
	int front;
	int rear;
};