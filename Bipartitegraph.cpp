//there a slight error in this code ,can refer to my gfg solution
#include<bits/stdc++.h>
using namespace std;
void undirected(unordered_map<int,vector<int>>&mp,vector<pair<int,int>>v,int m)
{

    for(int i=0;i<m;i++)
    {
        int vi=v[i].first;
        int ui=v[i].second;
        mp[vi].push_back(ui);
        mp[ui].push_back(vi);
        
    }
    for(int i=0;i<m;i++)
    {
        cout<<i<<" ->";
        for(int j=0;j<mp[i].size();j++)
        {
            cout<<mp[i][j]<<",";
            
        }
        cout<<endl;
    }
}
int bfs(int color[],unordered_map<int,vector<int>>mp,int node)
{
    queue<int>q ;
    q.push(node);
    color[node]=2;
    while(!q.empty())
    {
    int f=q.front();
    q.pop();
        for(auto it:mp[node])
    {
        if(color[it]==0)
        {
            color[it]=3-color[node];
            q.push(it);
        }
        else if(color[node]==color[it])
        {
            return 0;
            
        }
        
    }
    
    
    }
    return 1;
}


int main()
{
    int n; //vertex
    int m; //edges
    cin>>n;
    cin>>m;
    vector<pair<int,int>>v;
    for(int i=0;i<m;i++)
    {
        int u,vi;
        cin>>u>>vi;
        v.push_back({u,vi});
      
    }
    cout<<"printing of edges"<<endl;
    
    for(int i=0;i<m;i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    
    unordered_map<int,vector<int>>mp;
    undirected(mp,v,m);
    //bfs()
     int color[n]={0};
	    int c=1;
	    for(int i=0;i<n;i++)
	    {
	        if(color[i]==0)
	        {
	             c=bfs(color,mp,i);
	             if(c==0)
	             {
	                 cout<<"the graph is not bipartite";
	                 break;
	             }
	             
	        }
	    }
    cout<<"It is a bipartite graph";
    
}

