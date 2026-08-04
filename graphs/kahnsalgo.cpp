#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> topological(int n,vector<vector<int>>& adj){
    int indegree[n+1]={0};
    for(int i=1;i<n+1;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=1;i<n+1;i++){
        if(indegree[i]==0)
        q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
    }
    return topo;
}
int main(){
    int n,m;
    cout<<"Enter nodes and edges";
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> ans=topological(n,adj);
    for(auto it:ans){
        cout<<it<<" ";
    }
}