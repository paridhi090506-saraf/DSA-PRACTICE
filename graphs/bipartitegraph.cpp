#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool check(int start,int V,vector<vector<int>> &adj, int color[]){
    queue<int> q;
    q.push(start);
    color[start]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it : adj[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                q.push(it);
            }
            else if(color[it]==color[node]){
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int n,vector<vector<int>> &adj){
    int color[n+1];
    for(int i=0;i<n+1;i++)
    color[i]=-1;
    for(int i=0;i<n+1;i++){
        if(color[i]==-1){
            if(check(i,n,adj,color)==false){
                return false;
            }
        }
    }
    return true;
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
    if(isBipartite(n,adj)==true)
    cout<<"Bipartite graph";
    else
    cout<<"Not a bipartite graph";
}