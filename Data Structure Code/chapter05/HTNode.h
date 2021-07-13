#pragma once
#include <iostream>

class HTNode
{
public:
	HTNode();
	~HTNode();
	void CreateHuffmanTree(HTNode* HT, int n);
	int getParent();
	int getLChild();
	int getRChild();
	int getWeight();
	void setParent(int);
	void setLChild(int);
	void setRChild(int);
	void setWeight(int);
	void InOrderTraverse(HTNode* node,int n);
private:
	int weight;
	int parent;
	int lchild;
	int rchild;
};

void Select(HTNode* HT, int i, int& s1, int& s2);
