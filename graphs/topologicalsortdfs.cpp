#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void dfs(int node, int vis[], vector<vector<int>>&adj, stack<int>&st){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,st);
        }
    }
    st.push(node);
}
vector<int> topoSort(int n, vector<vector<int>>&adj){
    stack<int> st;
    int vis[n+1]={0};
    for(int i=1;i<n+1;i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);
    }
    vector<int> ans=topoSort(n,adj);
    for(auto it:ans)
    cout<<it<<" ";
}