#include<bits/stdc++.h>
using namespace std;
void directed(unordered_map<int,vector<int>>&mp,vector<pair<int,int>>v,int m)
{

    for(int i=0;i<m;i++)
    {
        int vi=v[i].first;
        int ui=v[i].second;
        mp[vi].push_back(ui);
       
        
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
void topo(unordered_map<int,bool>&status,unordered_map<int,vector<int>>mp,int m,vector<int>&ans,int node,stack<int>&s)
{
    ans.push_back(node);
    status[node]=1;
    for(auto it:mp[node])
    {
        if(status[it]!=1)
        {
            topo(status,mp,m,ans,it,s);
        }
        
    }
    s.push(node);
    
    
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
    directed(mp,v,m);
    //dfs()
    stack<int>s;
    unordered_map<int,bool>status;
    for(int i=0;i<n;i++)
    {
        if(status[i]==0)
        {
            topo(status,mp,m,ans,i,s);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
   
    
    
}



