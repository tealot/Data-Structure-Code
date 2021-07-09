#include "Matching.h"
Status Matching()
{
    SqStack<char>* st = new SqStack<char>();
    int flag = 1;
    char ch;
    cin >> ch;
    while (ch != '#' && flag)
    {
        switch (ch)
        {
        case '[':
        case '(':
            st->Push(ch);
            break;
        case ')':
            if (!st->StackEmpty() && st->GetTop() == '(')
            {
                char x;
                st->Pop(x);
            }
            else
            {
                flag = 0;
            }
            break;
        case ']':
            if (!st->StackEmpty() && st->GetTop() == '[')
            {
                char x;
                st->Pop(x);
            }
            else
            {
                flag = 0;
            }
            break;
        }
        cin >> ch;
    }
    if (st->StackEmpty() && flag)
    {
        return true;
    }
    else
    {
        return false;
    }
}