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
	int ListLength()
	{
		int length = 0;
		LinkList* p = this;
		while (p)
		{
			p = p->next;
			j++;
		}
	}
	void MergeList(LinkList LB)
	{
		int m = this->ListLength();
		int n = LB.ListLength();
		for (int i = 0; i <= n; i + )
		{
			LinkList* e;
			LB.GetElem(i, e);
			if (!this->LocateElem(e))
			{
				this->ListInsert(++m, e);
			}
		}
	}
	LinkList* getNext()
	{
		return this->next;
	}
	T* getData()
	{
		return this->data;
	}
	void MergeList_L(LinkList& LB)
	{
		LinkList* pa = this->getNext();
		LinkList* pb = LB.getNext();
		LinkList* LC = this;
		LinkList* pc = LC;
		while (pa&&pb)
		{
			if (pa->getData() <= pb->getData())
			{
				pc->getNext() = pa;
				pc = pa;
				pa = pa->getNext();
			}
			else
			{
				pc->getNext() = pb;
				pc = pb;
				pb = pb->getNext();
			}
		}
		pc->getNext() = pa ? pa : pb;
		delete LB;
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