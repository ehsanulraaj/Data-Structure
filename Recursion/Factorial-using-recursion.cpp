/* Ehsanul Haque Chowdhury Raaj
2310476125 */

#include<bits/stdc++.h>
using namespace std;

long long int factorial(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    return n*factorial(n-1);
}

int main()
{
    int num;
    cout<<"Enter the number: ";
    cin>>num;

    if(num<0)
    {
        cout<<"Negative numbers have no factorial value!";
        exit(1);
    }
    else if(num > 20)
    {
        cout<<"Overflow!\nThe number should be less than or equal 20.\n";
    }
    else
    {
        cout<<"Factorial of "<<num<<" = "<<factorial(num)<<"\n";
    }

    return 0;
}

