#pragma once
#include <iostream>
#include "SqQueue.h"

class Person
{
public:
	Person();
	~Person();
	string getName();
	void setName(string n);
	char getSex();
	void setSex(char s);
private:
	string name;
	char sex;
};

void DancePartner(Person dancer[], int num);