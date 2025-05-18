/* Ehsanul Haque Chowdhury Raaj
2310476125 */

#include<bits/stdc++.h>
using namespace std;

int vertex;
int pathmatrix[100][100];
int B[100][100][100];

void multiply(int a, int b, int c)
{
    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j<vertex; j++)
        {
            int x=0;
            for(int k=0; k<vertex; k++)
            {
                x+= B[a][i][k]*B[b][k][j];
            }
            B[c][i][j]=x;
        }
    }
}

int main()
{
    cout<<"Enter the number of vertices: ";
    cin>>vertex;

    cout<<"Enter the adjacency matrix: \n";
    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j<vertex; j++)
        {
            cin>>B[0][i][j];
            B[1][i][j]=B[0][i][j];
        }
    }

    for(int p=2; p<vertex; p++)
    {
        multiply(0, p-1, p);
    }

    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j<vertex; j++)
        {
            pathmatrix[i][j]=0;
            for(int k=1; k<vertex; k++)
            {
                if(B[k][i][j]>0)
                {
                    pathmatrix[i][j]=1;
                    break;
                }
            }
        }
    }

    int path=0;
    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j< vertex; j++)
        {
            if(pathmatrix[i][j]==1)
            {
                path++;
            }
        }
    }


    if(vertex==1 || path==vertex*vertex)
    {
        cout<<"The path matrix is strongly connected\n";
    }
    else
    {
        cout<<"The path matrix is not strongly connected\n";
    }

    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j< vertex; j++)
        {
            cout<<pathmatrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;

}
