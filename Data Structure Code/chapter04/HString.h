#pragma once

#include <iostream>

#define MAXSIZE 100
#define MAXLEN 255
#define OK 1
#define ERROR 0
#define OVERFLOW -2

class HString
{
public:
	HString();
	~HString();

private:
	char* ch;
	int length;
};

HString::HString()
{
}

HString::~HString()
{
}