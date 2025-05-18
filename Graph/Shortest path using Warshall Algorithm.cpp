/* Ehsanul Haque Chowdhury Raaj
2310476125 */

#include<bits/stdc++.h>
using namespace std;

int vertex, INF = 1e9 ;
int weight[100][100];

int main()
{
    cout<<"Enter the number of vertices: ";
    cin>>vertex;

    cout<<"Enter the weighted matrix: \n";
    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j<vertex; j++)
        {
            cin>>weight[i][j];
            if(weight[i][j]==0)
            {
                weight[i][j]=INF;
            }
        }
    }


    for(int k=0; k<vertex; k++)
    {
        for(int i=0; i<vertex; i++)
        {
            for(int j=0; j<vertex; j++)
            {
                if(weight[i][j]>weight[i][k]+weight[k][j])
                {
                    weight[i][j]=weight[i][k]+weight[k][j];
                }
            }
        }
    }

    cout<<"Shortest path Matrix: \n";
    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j<vertex; j++)
        {
            if(weight[i][j]==INF)
            {
                cout<<"INF"<<" ";
            }
            else
            {
                cout<<weight[i][j]<<" ";

            }
        }
        cout<<"\n";
    }

    return 0;

}
