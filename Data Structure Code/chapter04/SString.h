#pragma once

#include <iostream>

#define MAXSIZE 100
#define MAXLEN 255
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

class SString
{
public:
	SString();
	SString(char c[]);
;	~SString();
	char* getCh();
	void setCh(char c[]);
	int getLength();
	void setLength(int);
	int Index_BF(SString T, int pos);
	int Index_KMP(SString T, int pos);
	void get_Next( int next[]);
	void get_nextVal( int nextval[]);
private:
	char ch[MAXLEN + 1];
	int length;
};