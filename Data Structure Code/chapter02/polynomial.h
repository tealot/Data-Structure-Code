#pragma once
#include<iostream>
using namespace std;
typedef Polynomial PNode;
class Polynomial
{
public:
	Polynomial();
	~Polynomial();
	void CreatePolyn(int n);
	void setCoef()
	{
		cin >> this->coef;
	}
	void setExpn()
	{
		cin >> this->expn;
	}
	float getCoef()
	{
		return this->coef;
	}
	int getExpn()
	{
		return this->expn;
	}
private:
	float coef;
	int expn;
	PNode* next;
};

Polynomial::Polynomial()
{
}

Polynomial::~Polynomial()
{
}

void Polynomial::CreatePolyn(int n)
{
	PNode* P = new PNode();
	P->next = nullptr;
	PNode* pre;
	PNode* q;
	for (int i = 1; i <= n; i++)
	{
		PNode* s = new PNode();
		s->setCoef();
		s->setExpn();
		pre = P;
		q = P->next;
		while (q && q->getExpn() < s->getExpn())
		{
			pre = q;
			q = q->next;
		}
		s->next = q;
		pre->next = s;
	}
}

