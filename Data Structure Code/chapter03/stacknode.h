#pragma once
#include <iostream>

using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

template <class T>
class StackNode
{
public:
	StackNode()
	{
		this = NULL;
		return OK;
	}
	~StackNode();
	void setData(T e)
	{
		this->data = e;
	}
	void setNext(StackNode* p)
	{
		this->next = p;
	}
	StackNode* getNext()
	{
		return this->next;
	}
	T getData()
	{
		return this->data;
	}
	Status Push(T e)
	{
		StackNode* p = new StackNode();
		p->setData(e);
		p->setNext(this);
		this = p;
		return OK;
	}
	Status Pop(T& e)
	{
		if (this == nullptr)
		{
			return ERROR;
		}
		e = this->getData();
		StackNode* p = this;
		this = this->getNext();
		delete p;
		return OK;
	}
	T GetTop()
	{
		if (this != nullptr)
		{
			return this->getData();
		}
	}
private:
	T data;
	StackNode* next;
};