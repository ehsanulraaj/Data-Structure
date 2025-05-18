/* Ehsanul Haque Chowdhury Raaj
2310476125 */

#include <bits/stdc++.h>
using namespace std;

int fibonacci(int i)
{
    if(i==0||i==1)
    {
        return i;
    }
    return fibonacci(i-1)+fibonacci(i-2);
}

int main()
{
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    if(num<0)
    {
        cout<<"The number can't be negative.\n";
        exit(1);
    }
    cout<<"First "<<num<<" numbers of the fibonacci series:\n";
    for(int i=0; i<num; i++)
    {
        cout<<fibonacci(i)<<" ";
    }
    return 0;
}

