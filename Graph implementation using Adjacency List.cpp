//Graph implementation using Adjacency list 
//It does Space optimisation O(vertex+edges)
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adj;
    void addEdge(int u,int v,bool direction){
        //direction->0 (undirected Graph)
        //direction->1(directed)
        
        //create a edge from u to v
        adj[u].push_back(v);
        if(direction ==0)
        {
            adj[v].push_back(u);
        }
    }
        //printing a Graph
        void printGraph()
        {
            for(auto i:adj)
        {
            cout<<i.first<<"  "<<"->";
            for(auto j:i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
            
        }
        
    
    
};
int main()
{
    int n;
    cout<<"Enter the number of vertices";
    cin>>n;
    int m;
    cout<<"Enter the number of edges";
    cin>>m;
    Graph g;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        //creating an undirected Graph
        g.addEdge(u,v,0);
        
    }
    g.printGraph();
    
    
}
