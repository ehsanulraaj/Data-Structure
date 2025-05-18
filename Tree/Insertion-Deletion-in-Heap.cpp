/* Ehsanul Haque Chowdhury Raaj
2310476125 */

#include<bits/stdc++.h>
using namespace std;

int heap[100] = {0};

void insert(int data, int pos)
{
    while(pos > 0)
    {
        int parent = (pos-1)/2;
        if(heap[parent]>=data)
        {
            heap[pos]=data;
            return;
        }
        heap[pos] = heap[parent];
        pos = parent;
    }
    heap[pos] = data;
}

int remove(int data, int size)
{
    int pos;
    for(pos=0; pos<size; pos++)
    {
        if(heap[pos]==data)
        {
            break;
        }
    }
    if(pos==size)
    {
        cout<<"The data "<<data<<" is not found."<<endl;
        return size;
    }
    while(pos<size/2)
    {
        int left=pos*2+1, right=pos*2+2;
        if(heap[left]>=heap[right])
        {
            heap[pos]=heap[left];
            pos=left;
        }
        else
        {
            heap[pos]= heap[right];
            pos = right;
        }
    }
    heap[pos] = heap[size-1];
    return size-1;

}

void display(int arr[], int size)
{
    int i, j, space, linegap, level = log2(size)+1;
    for(i = 0; i<level; i++)
    {
        for(j=0; (j<(1<<i) && size--) ; j++)
        {
            space = (1<<(level-i))-1;
            if(j==0)
            {
                space /=2;
            }
            while(space--)
            {
                cout<<" ";
            }
            cout<<arr[(1<<i)-1+j];
        }
        for(linegap =0; linegap < (1<<(level-i-2)); linegap++)
        {

            cout<<"\n";
        }
    }
}

int main()
{
    int size = 10;
    int arr[size] = {9,5,7,2,6,8,2,3,4,2};
    for(int i = 0; i<size; i++)
    {
        insert(arr[i], i);
    }
    display(heap, size);
    int data;
    cout<<"\nEnter the value you want to remove: ";
    cin>>data;
    size = remove(data, size);
    display(heap, size);
    return 0;
}
