#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool cycleDetection(vector<vector<int>> & adj, int src, int vis[]){
    queue<pair<int,int>> q;
    vis[src]=1;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                vis[adjNode]=1;
                q.push({adjNode,node});
            }
            else if(parent!=adjNode){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(vector<vector<int>> & adj,int V){
    int vis[V+1]={0};
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            if(cycleDetection(adj,i,vis))
            return true;
        }
    }
    return false;
}
int main(){
    cout<<"Enter nodes and edges"<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isCycle(adj,n)){
        cout<<"Cycle exists";
    }
    else{
        cout<<"No cycle exists";
    }
}