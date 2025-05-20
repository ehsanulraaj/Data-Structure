/* Ehsanul Haque Chowdhury Raaj
2310476125 */

#include<bits/stdc++.h>
using namespace std;

int calculate(int operand1, int operand2, char a)
{
    if(a == '+')
    {
        return operand1+operand2;
    }
    else if(a == '-')
    {
        return operand1-operand2;
    }
    else if(a == '*')
    {
        return operand1 * operand2;
    }
    else if(a == '/')
    {
        return operand1 / operand2;
    }
    else
    {
        int result = 1;
        while(operand2)
        {
             result *= operand1;
             operand2--;
        }
        return result;
    }
}

int push(int stk[], int top, int a)
{
    stk[++top] = a;
    return top;
}

int pop(int stk[], int top)
{
    return --top;
}

int prefixEvaluation(string prefix)
{
    int n = prefix.size();
    int stk[100];
    int top = -1;
    int operand1, operand2;

    for(int i = 0; i<n; i++)
    {
        if(prefix[i] >= '0' && prefix[i] <= '9')
        {
            top = push(stk, top, prefix[i]-'0');
        }
        else
        {
            operand2 = stk[top];
            top = pop(stk, top);
            operand1 = stk[top];
            top = pop(stk, top);
            top = push(stk, top, calculate(operand1, operand2, prefix[i]));
        }
    }
    return stk[top];

}

int main()
{
    string prefix;
    cout<<"Enter prefix notation: ";
    cin>> prefix;
    cout<<"Result: "<<prefixEvaluation(prefix);
    return 0;
}
