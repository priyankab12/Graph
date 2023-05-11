//Graph implementation using Adjacency Matrix
//Matrix size is equal to the no of vertix*vertix
#include<iostream>
using namespace std;
const int N=1e3+10;
int Graph[N][N];
int main()
{
    
    int n,m;
    //or instead of global we can do this declaration -> Graph[n+1][n+1]
    cout<<"enter the number of vertex";
    cin>>n;
    cout<<"enter the number of edges";
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        Graph[v1][v2]=1;
        Graph[v2][v1]=1;
        
    }
    //Drawbacks---->Space complexity->O(n^2);
                    //we cannot make a matrix of size >10^3 as it is not fessible to store more than this in memory
    
    
}
