#pragma once
#include <iostream>

template <class T>
class LinkList
{
public:
	LinkList()
	{

	}
	~LinkList()
	{

	}

private:
	T data;
	LinkList* next;
};