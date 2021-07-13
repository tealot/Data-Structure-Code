#pragma once
#include <iostream>

template <class T>
class BiThrNode
{
public:
	BiThrNode()
	{

	}
	~BiThrNode()
	{

	}
	BiThrNode* getLChild()
	{
		return this->lchild;
	}
	void setLChild(BiThrNode* l)
	{
		this->lchild = l;
	}
	BiThrNode* getRChild()
	{
		return this->rchild;
	}
	void setRChild(BiThrNode* r)
	{
		this->rchild = r;
	}
	int getLTag()
	{
		return this->LTag;
	}
	void setLTag(int tag)
	{
		this->LTag = tag;
	}
	int getRTag()
	{
		return this->RTag;
	}
	void setRTag(int tag)
	{
		this->RTag = tag;
	}
	T getData()
	{
		return this->data;
	}
	void setData(T d)
	{
		this->data = d;
	}
	void InThreading(BiThrNode* p)
	{
		if (p)
		{
			p->InThreading(p->getLChild());
			if (!p->getLChild())
			{
				p->setLTag(1);
				p->setLChild(pre);
			}
			else
			{
				p->setLTag(0);
			}
			if (!pre->getRChild())
			{
				pre->setRTag(1);
				pre->setRChild(p);
			}
			else
			{
				pre->setRTag(0);
			}
			pre = p;
			p->InThreading(p->getRChild());
		}
	}
	void InOrderThreading(BiThrNode* Thrt, BiThrNode* root)
	{
		Thrt = new BiThrNode();
		Thrt->setLTag(0);
		Thrt->setRTag(1);
		Thrt->setRChild(Thrt);
		if (!root)
		{
			Thrt->setLChild(Thrt);
		}
		else
		{
			Thrt->setLChild(root);
			pre = Thrt;
			InThreading(root);
			pre->setRChild(Thrt);
			pre->setRTag(1);
			Thrt->setRChild(pre);
		}
	}
	void InOrderTraverse_Thr(BiThrNode* root)
	{
		BiThrNode* p = root->getLChild();
		while (p != root)
		{
			while (p->getLTag() == 0)
			{
				p = p->getLChild();
			}
			std::cout << p->getData();
			while(p->getRTag() == 1 && p->getRChild() != root)
			{
				p = p->getRChild();
				std::cout << p->getData();
			}
			p == p->getRChild();
		}
	}
private:
	T data;
	BiThrNode* lchild;
	BiThrNode* rchild;
	int LTag;
	int RTag;
	static BiThrNode* pre;
};
