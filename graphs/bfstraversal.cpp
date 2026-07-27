#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> bfs(int v,  vector<vector<int>> &adj){
    queue<int> q;
    vector<int> bfstrav;
    int vis[v+1]={0};
    vis[1]=1;
    q.push(1);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfstrav.push_back(node);
        for(int it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfstrav;
}
int main(){
    cout<<"Enter nodes and edges";
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> bfsTrav=bfs(n,adj);
    for(int x:bfsTrav){
        cout<<x<<" ";
    }
}