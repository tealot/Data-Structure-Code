#include "HTNode.h"

HTNode::HTNode()
{
}

HTNode::~HTNode()
{
}

int HTNode::getWeight()
{
	return this->weight;
}

void HTNode::setWeight(int weight)
{
	this->weight = weight;
}

int HTNode::getParent()
{
	return this->parent;
}

void HTNode::setParent(int parent)
{
	this->parent = parent;
}

int HTNode::getLChild()
{
	return this->lchild;
}

void HTNode::setLChild(int child)
{
	this->lchild = child;
}

int HTNode::getRChild()
{
	return this->rchild;
}

void HTNode::setRChild(int child)
{
	this->rchild = child;
}

void HTNode::CreateHuffmanTree(HTNode* HT, int n)
{
	if (n <= 1)
	{
		return;
	}
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (int i = 1; i <= m; i++)
	{
		HT[i].setParent(0);
		HT[i].setLChild(0);
		HT[i].setRChild(0);
	}
	for (int i = 1; i <= n; ++i)
	{
		int weight;
		std::cin >> weight;
		HT[i].setWeight(weight);
	}
	for (int i = n + 1; i <= m; i++)
	{
		int s1;
		int s2;
		Select(HT, i - 1, s1, s2);
		std::cout << s1 << ":" << s2 << std::endl;
		HT[s1].setParent(i);
		HT[s2].setParent(i);
		HT[i].setLChild(s1);
		HT[i].setRChild(s2);
		HT[i].setWeight(HT[s1].getWeight() + HT[s2].getWeight());
	}
	std::cout << std::endl;

	for (int i = 1; i <= m; i++)
	{
		std::cout << HT[i].getWeight() << '\t';
	}
	std::cout << std::endl;
	InOrderTraverse(HT, m);

}

void Select(HTNode* HT, int i, int& s1, int& s2)
{
	s1 = NULL;
	s2 = NULL;
	for (int n = 1; n <= i; n++)
	{
		if (HT[n].getParent() == 0)
		{
			if (s1 == NULL)
			{
				s1 = n;
			}
			else if (s2 == NULL)
			{
				s2 = n;
			}
			else if (HT[s1].getWeight() > HT[s2].getWeight() && HT[n].getWeight() > HT[s2].getWeight())
			{
				s2 = n;
			}
			else if (HT[s2].getWeight() > HT[s1].getWeight() && HT[n].getWeight() > HT[s1].getWeight())
			{
				s1 = n;
			}
		}
	}
	for (int n = 1; n <= i; n++)
	{
		if (HT[n].getParent() == 0 && n != s1 && n != s2)
		{
			if (HT[s2].getWeight() <= HT[s1].getWeight() && HT[n].getWeight() < HT[s1].getWeight())
			{
				s1 = n;
			}
			else if (HT[s1].getWeight() <= HT[s2].getWeight() && HT[n].getWeight() < HT[s2].getWeight())
			{
				s2 = n;
			}
		}
	}
}

void HTNode::InOrderTraverse(HTNode* node, int n)
{
	std::cout << node[n].getWeight() << '\t';
	if (node[n].getLChild())
	{
		InOrderTraverse(node, node[n].getLChild());
	}
	if (node[n].getRChild())
	{
		InOrderTraverse(node, node[n].getRChild());
	}
}