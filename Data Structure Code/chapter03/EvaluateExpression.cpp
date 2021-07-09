#include "EvaluateExpression.h"
char compare(char a1, char a2)
{
    if (a1 == '+' && a2 == '+')return '>';
    else if (a1 == '+' && a2 == '-') return '>';
    else if (a1 == '+' && a2 == '*') return '<';
    else if (a1 == '+' && a2 == '/')return '<';
    else if (a1 == '+' && a2 == '(')return '<';
    else if (a1 == '+' && a2 == ')')return '>';
    else if (a1 == '+' && a2 == '#')return '>';
    else if (a1 == '-' && a2 == '+')return '>';
    else if (a1 == '-' && a2 == '-')return '>';
    else if (a1 == '-' && a2 == '*')return '<';
    else if (a1 == '-' && a2 == '/')return '<';
    else if (a1 == '-' && a2 == '(')return '<';
    else if (a1 == '-' && a2 == ')')return '>';
    else if (a1 == '-' && a2 == '#')return '>';
    else if (a1 == '*' && a2 == '+')return '>';
    else if (a1 == '*' && a2 == '-')return '>';
    else if (a1 == '*' && a2 == '*')return '>';
    else if (a1 == '*' && a2 == '/')return '>';
    else if (a1 == '*' && a2 == '(')return '<';
    else if (a1 == '*' && a2 == ')')return '>';
    else if (a1 == '*' && a2 == '#')return '>';
    else if (a1 == '/' && a2 == '+')return '>';
    else if (a1 == '/' && a2 == '-')return '>';
    else if (a1 == '/' && a2 == '*')return '>';
    else if (a1 == '/' && a2 == '/')return '>';
    else if (a1 == '/' && a2 == '(')return '<';
    else if (a1 == '/' && a2 == ')')return '>';
    else if (a1 == '/' && a2 == '#')return '>';
    else if (a1 == '(' && a2 == '+')return '<';
    else if (a1 == '(' && a2 == '-')return '<';
    else if (a1 == '(' && a2 == '*')return '<';
    else if (a1 == '(' && a2 == '/')return '<';
    else if (a1 == '(' && a2 == '(')return '<';
    else if (a1 == '(' && a2 == ')')return '=';
    else if (a1 == ')' && a2 == '+')return '>';
    else if (a1 == ')' && a2 == '-')return '>';
    else if (a1 == ')' && a2 == '*')return '>';
    else if (a1 == ')' && a2 == '/')return '>';
    else if (a1 == ')' && a2 == ')')return '>';
    else if (a1 == ')' && a2 == '#')return '>';
    else if (a1 == '#' && a2 == '+')return '<';
    else if (a1 == '#' && a2 == '-')return '<';
    else if (a1 == '#' && a2 == '*')return '<';
    else if (a1 == '#' && a2 == '/')return '<';
    else if (a1 == '#' && a2 == '(')return '<';
    else if (a1 == '#' && a2 == '#')return '=';
    else return ' ';
}

double Operate(double a, char theta, double b)
{
    double c;
    switch (theta)
    {
    case '+':
        c = a + b;
        cout << a << '+' << b << '=' << c << endl;
        break;
    case '-':
        c = a - b;
        cout << a << '-' << b << '=' << c << endl;
        return a - b;
    case '*':
        c = a * b;
        cout << a << '*' << b << '=' << c << endl;
        return a * b;
    case '/':
        c = a / b;
        cout << a << '/' << b << '=' << c << endl;
        return a / b;
    default:
        break;
    }
    return c;
}

bool In(char ch)
{
    return isdigit(ch) != 0;
}

double EvaluateExpression()
{
    SqStack<double>* OPND = new SqStack<double>();
    SqStack<char>* OPTR = new SqStack<char>();
    OPTR->Push('#');
    char ch;
    cin >> ch;
    while (ch != '#' || OPTR->GetTop() != '#')
    {
        if (In(ch))
        {
            OPND->Push(atoi(&ch));
            cin >> ch;
        }
        else
        {
            switch (compare(OPTR->GetTop(), ch))
            {
            case '<':
                OPTR->Push(ch);
                cin >> ch;
                break;
            case '>':
                char theta;
                OPTR->Pop(theta);
                double b;
                double a;
                OPND->Pop(b);
                OPND->Pop(a);
                OPND->Push(Operate(a, theta, b));
                break;
            case '=':
                char x;
                OPTR->Pop(x);
                cin >> ch;
                break;
            }
        }
    }
    return OPND->GetTop();
}