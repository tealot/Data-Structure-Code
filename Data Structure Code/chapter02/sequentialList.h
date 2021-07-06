#pragma once
#include <iostream>

using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

template <class T>
class SqList
{
private:
    /* data */
    T* elem;
    int length;
    Status InitList()
    {
        this->elem = new T[MAXSIZE];
        if (!this->elem)
        {
            cout << "¥Ê¥¢∑÷≈‰ ß∞‹";
        }
        return OK;
    }
public:
    SqList(/* args */)
    {
        this->InitList();
    }
    ~SqList()
    {
    }
    //»°÷µ
    Status getElem(int i, T& e)
    {
        if (i<1 || i>this->length)
        {
            return ERROR;
        }
        e = this->elem[i - 1];

        return OK;
    }
    //≤È’“
    int LocateElem(T e)
    {
        for (int i = 0; i < this->length; i++)
        {
            if (this->elem[i] == e)
            {
                return i + 1;
            }
        }
        return 0;
    }
    //≤Â»Î
    Status ListInsert(int i, T e)
    {
        if ((i < 1) || (i > this->length + 1))
        {
            return ERROR;
        }
        for (int j = this->length; j >= i - 1; j--)
        {
            this->elem[j + 1] = this->elem[j];
        }
        this->elem[i - 1] = e;
        this->length++;
        return OK;
    }
    //…æ≥˝
    Status ListDelete(int i)
    {
        if ((i < 1) || (i > this->length))
        {
            return ERROR;
        }
        for (int j = i; j <= this->length; j++)
        {
            this->elem[i - 1] = this->elem[i];
        }
        --this->length;
        return OK;
    }
    void toString()
    {
        for (int i = 0; i < this->length; i++)
        {
            cout << this->elem[i];
        }
    }
};