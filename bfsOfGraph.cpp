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
void bfs(unordered_map<int,bool>&status,unordered_map<int,vector<int>>mp,int m,vector<int>&ans,int node)
{
    queue<int>q ;
    q.push(node);
    while(!q.empty())
    {
    status[node]=1;
    int f=q.front();
    q.pop();
    ans.push_back(f);
    
        for(auto it:mp[node])
    {
        if(status[it]==0)
        {
            q.push(it);
            status[it]=1;
            
        }
        
    }
    
    }
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
    vector<int>ans;
    unordered_map<int,vector<int>>mp;
    undirected(mp,v,m);
    //bfs()
    unordered_map<int,bool>status;
    for(int i=0;i<n;i++)
    {
        if(status[i]==0)
        {
            bfs(status,mp,m,ans,i);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    
}
