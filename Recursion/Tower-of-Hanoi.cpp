/* Ehsanul Haque Chowdhury Raaj
2310476125 */

#include<bits/stdc++.h>
using namespace std;

int totalSteps(int disks)
{
    if(disks == 1)
    {
        return 1;
    }
    return (1 + 2*totalSteps(disks-1));
}
void towerOfHanoy(int begin, int end, int middle, int disks)
{
    if(disks == 1)
    {
        cout<<begin<<" "<<end<<"\n";
    }
    else
    {
        towerOfHanoy(begin, middle, end, disks-1);
        cout<<begin<<" "<<end<<"\n";
        towerOfHanoy(middle, end, begin, disks-1);
    }
}
int main()
{
    int disks;
    cout<<"Enter Number of disks: ";
    cin>>disks;
    cout<<"Number of steps: "<<totalSteps(disks)<<"\n";
    towerOfHanoy(1, 3, 2, disks);
    return 0;
}
