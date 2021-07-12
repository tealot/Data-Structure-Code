#pragma once

#include <iostream>

#define MAXSIZE 100
#define MAXLEN 255
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef enum{ATOM,LIST} ElemTag;

template <class T>
class GList
{
public:
	GList()
	{

	}
	~GList()
	{

	}

private:
	ElemTag tag;
	union
	{
		T atom;
		class{
			GList* hp;
			GList* tp;
		}ptr;
	};
};