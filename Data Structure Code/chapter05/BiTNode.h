#pragma once
#include <iostream>
#include "../chapter03/stack.h"

template <class T>
class BiTNode
{
public:
	BiTNode()
	{

	}
	~BiTNode()
	{

	}
	BiTNode* getLChild()
	{
		return this->lchild;
	}
	void setLChild(BiTNode* l)
	{
		this->lchild = l;
	}
	BiTNode* getRChild()
	{
		return this->rchild;
	}
	void setRChild(BiTNode* r)
	{
		this->rchild = r;
	}
	T getData()
	{
		return this->data;
	}
	void setData(T d)
	{
		this->data = d;
	}
	void InOrderTraverse(BiTNode* node)
	{
		if (node)
		{
			InOrderTraverse(node->getLChild());
			std::cout << node->getData();
			InOrderTraverse(node->getRChild());
		}
	}
	void InOrderTraverseByStack(BiTNode node)
	{
		SqStack<BiTNode>* stack = new SqStack<BiTNode>();
		BiTNode p = node;
		BiTNode q = new BiTNode();
		while (p || !stack->StackEmpty())
		{
			if (p)
			{
				stack->Push(p);
				p = p.getLChild();
			}
			else
			{
				stack->Pop(q);
				cout << q.getData();
				p = q.getRChild();
			}
		}
	}
	BiTNode* CreateBiTree(BiTNode* node)
	{
		T ch;
		cin >> ch;
		if (ch == '#')
		{
			node = nullptr;
		}
		else
		{
			if (!node)
			{
				node = new BiTNode();
			}
			node->setData(ch);
			//std::cout << node->getData();
			node->setLChild(node->CreateBiTree(node->getLChild()));
			node->setRChild(node->CreateBiTree(node->getRChild()));
		}
		return node;
	}
	BiTNode* copy(BiTNode* root, BiTNode* NewT)
	{
		if (root == nullptr)
		{
			NewT = nullptr;
		}
		else
		{
			if (!NewT)
			{
				NewT = new BiTNode();
			}
			NewT->setData(root->getData());
			NewT->setLChild(NewT->copy(root->getLChild(), NewT->getLChild()));
			NewT->setRChild(NewT->copy(root->getRChild(), NewT->getRChild()));
		}
		return NewT;
	}
	int Depth(BiTNode *root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		else
		{
			int m = root->Depth(root->getLChild());
			int n = root->Depth(root->getRChild());
			if (m > n)
			{
				return m + 1;
			}
			else
			{
				return n + 1;
			}
		}
	}
	int NodeCount(BiTNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		else
		{
			return root->NodeCount(root->getLChild()) + root->NodeCount(root->getRChild()) + 1;
		}
	}
private:
	T data;
	BiTNode* lchild;
	BiTNode* rchild;
};