/* Ehsanul Haque Chowdhury Raaj
 2310476125 */

#include<bits/stdc++.h>
using namespace std;

int precedence(char a)
{
    if(a == '+' || a == '-')
    {
        return 1;
    }
    if(a == '*' || a == '/')
    {
        return 2;
    }
    if(a == '^')
    {
        return 3;
    }
}

int push(char stk[], int top, char a)
{
    stk[++top] = a;
    return top;
}

int pop(char stk[], int top)
{
    return --top;
}

string infixToPostfix(string infix)
{
    char stk[100];
    int top = -1;
    string postfix = "";
    int n = infix.size();
    top = push(stk, top, '(');

    for(int i=0; i<n ; i++)
    {
        if(infix[i] == '(')
        {
            top = push(stk, top, infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(stk[top] != '(')
            {
                postfix += stk[top];
                top = pop(stk, top);
            }
            top = pop(stk, top);
        }
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            while(stk[top] != '(' && precedence(infix[i]) <= precedence(stk[top]))
            {
                postfix += stk[top];
                top = pop(stk, top);
            }
            top = push(stk, top, infix[i]);
        }
        else
        {
            postfix += infix[i];
        }
    }

    while(stk[top] != '(')
    {
        postfix += stk[top];
        top = pop(stk, top);
    }

    return postfix;
}

int main()
{
    string infix;
    cout<<"Enter infix expression: ";
    cin>>infix;
    cout<<"Postfix Expression: "<<infixToPostfix(infix);
    return 0;
}
