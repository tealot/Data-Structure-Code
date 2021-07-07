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
    T* getHead()
    {
        return this->elem;
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
    int ListLength()
    {
        return this->length;
    }
    void My_MergeList_Sq(SqList a, SqList b)
    {
        T c = new T[a.ListLength()+b.ListLength()];
        int a_num = 0;
        int b_num = 0;
        int c_num = 0;
        while (a_num!=a.ListLength()&&b_num!=b.ListLength())
        {
            if (a[a_num] <= b[b_num])
            {
                c[c_num] = a[a_num];
                a_num++;
            }
            else
            {
                c[c_num] = b[b_num];
                b_num++;
            }
            c_num++;
        }
        while (a_num != a.ListLength())
        {
            c[c_num] = a[a_num];
            a_num++;
            c_num++;
        }
        while (b_num != b.ListLength())
        {
            c[c_num] = b[b_num];
            b_num++;
            c_num++;
        }
    }
    void MeregeList_Sq(SqList a, SqList b)
    {
        this->length = a.ListLength() + b.ListLength();
        this->elem = new T[this->length];
        SqList* pc = this->elem;
        SqList* pa = a.getHead();
        SqList* pb = b.getHead();
        SqList* pa_last = a.getHead() + a.ListLength() - 1;
        SqList* pb_last = b.getHead() + b.ListLength() - 1;
        while ((pa<=pa_last)&&(pb<=pb_last))
        {
            if (*pa <= *pb)
                *pc++ = *pa++;
            else
                *pc++ = *pb++;
        }
        while (pa<pa_last)
        {
            *pc++ = *pa++;
        }
        while (pb<pb_last)
        {
            *pc++ = *pb++;
        }
    }
};