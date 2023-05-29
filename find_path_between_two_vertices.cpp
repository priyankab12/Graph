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
void dfs(int &flag,int node,int dest,unordered_map<int,bool>&status,unordered_map<int,vector<int>>mp,int m)
{
    status[node]=1;
    if(dest==node)
    { 
        flag=1;
    }
    for(auto it:mp[node])
    {
        if(status[it]!=1)
        {
            dfs(flag,it,dest,status,mp,m);
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
    unordered_map<int,vector<int>>mp;
    undirected(mp,v,m);
    //dfs()
    unordered_map<int,bool>status;
    int source,dest;
    cout<<"enter source and dest";
    cin>>source>>dest;
    int flag=0;
    dfs(flag,source,dest,status,mp,m);
    if(flag==0)
    cout<<"No path does not exist";
    else
    cout<<"Yes path exist ";
    
    
}



