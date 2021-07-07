#pragma once

#include <iostream>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

template <class T>
class DuLnode
{
public:
	DuLnode()
	{

	}
	~DuLnode()
	{

	}
	DuLnode* GetElem_DuL(int i)
	{
		//TODO
		return OK;
	}
	Status ListInsert_DuL(int i, T e)
	{
		DuLnode* p = this->GetElem_DuL();
		if (!p)
		{
			return ERROR;
		}
		DuLnode* s = new DuLnode();
		s->data = e;
		s->prior = p->prior;
		p->prior->next = s;
		s->next = p;
		p->prior = s;
		return OK;
	}
	Status ListDelete_DuL(int i)
	{
		DuLnode* p = this->GetElem_DuL();
		if (!p)
		{
			return ERROR;
		}
		p->next->prior = p->prior;
		p->prior->next = p->next;
		delete p;
		return OK;
	}

private:
	T data;
	DuLnode* prior;
	DuLnode* next;
};