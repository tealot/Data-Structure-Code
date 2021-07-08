#pragma once
#include<iostream>

using namespace std;
class Polynomial;

typedef Polynomial PNode;

class Polynomial
{
public:
	Polynomial();
	~Polynomial();
	void CreatePolyn(int n);
	void setCoef(float coef)
	{
		this->coef=coef;
	}
	void setExpn(int expn)
	{
		this->expn=expn;
	}
	float getCoef()
	{
		return this->coef;
	}
	int getExpn()
	{
		return this->expn;
	}
	Polynomial* getNext()
	{
		return this->next;
	}
	void setNext(Polynomial* p)
	{
		this->next = p;
	}
	void AddPolyn(Polynomial& pb);
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
		s->setCoef(1);
		s->setExpn(1);
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

void Polynomial::AddPolyn(Polynomial& pb)
{
	Polynomial* p1 = this->next;
	Polynomial* p2 = pb.getNext();
	Polynomial* p3 = this;
	while (p1&& p2)
	{
		if (p1->getExpn() == p2->getExpn())
		{
			int sum = p1->getCoef() + p2->getCoef();
			if (sum != 0)
			{
				p1->setCoef(sum);
				p3->setNext(p1);
				p3 = p1;
				p1 = p1->getNext();
				PNode* r = p2;
				p2 = p2->getNext();
				delete r;
			}
			else
			{
				PNode* r = p1;
				p1 = p1->getNext();
				delete r;
				r = p2;
				p2 = p2->getNext();
				delete r;
			}
		}
		else if (p1->getExpn() < p2->getExpn())
		{
			p3->setNext(p1);
			p3 = p1;
			p1 = p1->getNext();
		}
		else
		{
			p3->setNext(p2);
			p3 = p2;
			p2 = p2->getNext();
		}
	}
	p3->setNext(p1 ? p1 : p2);
	delete &pb;
}