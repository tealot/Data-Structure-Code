#pragma once
#include <iostream>


#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

template <class T>
class LinkList
{
public:
	LinkList()
	{
		cout << this->InitList();
	}
	~LinkList()
	{

	}
	Status GetElem(int i, T& e)
	{
		LinkList* p = this->next;
		int j = 1;
		while (p && j < i)
		{
			p = p->next;
			++j;
		}
		if (!p || j > i)
		{
			return ERROR;
		}
		e = p->data;
		return OK;
	}
	LinkList* LocateElem(T e)
	{
		LinkList* p = this->next;
		while (p && p->data != e)
		{
			p = p->next;
		}
		return p;
	}
	Status ListInsert(int i, T e)
	{
		LinkList* p = this;
		int j = 0;
		while (p&&(j<i-1))
		{
			p = p->next;
			j++;
		}
		if (!p || j > i - 1)
		{
			return ERROR;
		}
		LinkList* s = new LinkList();
		s->data = e;
		s->next = p->next;
		p->next = s;
		return OK;
	}
	Status ListDelete(int i)
	{
		LinkList* p = this;
		int j = 0;
		while ((p->next) && (j < i - 1))
		{
			p = p->next;
			++j;
		}
		if (!(p->next) || (j > i - 1))
		{
			return ERROR;
		}
		LinkList* q = p->next;
		p->next = q->next;
		delete q;
		return OK;
	}

	void CreateList_H(int n)
	{
		LinkList* L = new LinkList();
		L->next = NULL;
		for (int i = 0; i < n; i++)
		{
			LinkList* p = new LinkList();
			p->data = new T();
			p->next = L->next;
			L->next = p;
		}
	}

	void CreateList_R(int n)
	{
		LinkList* L = new LinkList();
		L->next = NULL;
		LinkList* r = L;
		for (int i = 0; i < n; i++)
		{
			LinkList* p = new LinkList();
			p->next = NULL;
			r->next = p;
			r = p;
		}
	}

private:
	T data;
	LinkList* next;
	Status InitList()
	{
		this->next = NULL;
		return OK;
	}
};