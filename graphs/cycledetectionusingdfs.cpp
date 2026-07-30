#include<iostream>
#include<vector>
using namespace std;
bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>&adj){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfs(it,node,vis,adj)==true)
            return true;
        }
        else if(it!=parent){
            return true;
        }
    }
    return false;
}
bool isCycle(int n, vector<vector<int>>& adj){
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,-1,vis,adj))
                return true;
        }
    }
return false;
}
int main(){
    int n,m;
    vector<vector<int>> adj(n+1);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    if(isCycle(n,adj))
    cout<<"Cycle exists.";
    else
    cout<<"Cycle does not exist.";
}