#include "book.h"


Book::Book(/* args */)
{
    this->name = "";
    this->no = "";
    this->price = NULL;
}

Book::~Book()
{
}

Book::Book(string no, string name, float price)
{
    this->no = no;
    this->name = name;
    this->price = price;
}

string Book::getName()
{
    return this->name;
}