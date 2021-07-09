#pragma once
#include <iostream>

using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

template <class T>
class QNode
{
public:
	QNode()
	{
	}
	~QNode()
	{

	}
	void setNext(QNode* q)
	{
		this->next = q;
	}
	QNode* getNext()
	{
		return this->next;
	}
	void setData(T d)
	{
		this->data = d;
	}
	T getData()
	{
		return this->data;
	}
private:
	T data;
	QNode* next;
};

template <class T>
class LinkQueue
{
public:
	LinkQueue()
	{
		this->front = this->rear = new QNode<T>();
		this->front->setNext(nullptr);
	}
	~LinkQueue()
	{

	}
	Status EnQueue(T e)
	{
		QNode<T>* p = new QNode<T>();
		p->setData(e);
		p->setNext(nullptr);
		this->rear->setNext(p);
		this->rear = p;
		return OK;
	}
	Status DeQueue(T& e)
	{
		if (this->front == this->rear)
		{
			return ERROR;
		}
		QNode<T>* p = new QNode<T>();
		p = this->front->getNext();
		e = p->getData();
		this->front->setNext(p->getNext());
		if (this->rear == p)
		{
			this->rear = this->front;
		}
		delete p;
		return OK;
	}
	T getHead()
	{
		if (this->front != this->rear)
		{
			return this->front->getNext()->getData();
		}
	}
private:
	QNode<T>* front;
	QNode<T>* rear;
};

