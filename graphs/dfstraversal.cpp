#include<iostream>
#include<vector>
using namespace std;
void dfstrav(int node, vector<int>& ls, vector<vector<int>>& adj, int vis[]){
    vis[node]=1;
    ls.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            dfstrav(it,ls,adj,vis);
        }
    }
}
int main(){
    int n,m;
    cout<<"Enter nodes and edges";
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int vis[n+1]={0};
    vector<int> ls;
    int start=1;
    dfstrav(start,ls,adj,vis);
    cout << "DFS Traversal: ";
    for (int x : ls)
        cout << x << " ";
}
