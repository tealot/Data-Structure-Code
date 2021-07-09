#include "conversion.h"

void conversion(int N)
{
    SqStack<int>* st = new SqStack<int>();
    while (N)
    {
        st->Push(N % 8);
        N = N / 8;
    }
    while (!st->StackEmpty())
    {
        int e;
        st->Pop(e);
        cout << e;
    }
    cout << endl;
}