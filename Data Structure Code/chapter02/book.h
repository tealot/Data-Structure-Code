#pragma once
#include <iostream>

using namespace std;
class Book
{
public:
	Book();
	Book(string, string, float);
	~Book();
	string getName();
private:
	string no;
	string name;
	float price;
};