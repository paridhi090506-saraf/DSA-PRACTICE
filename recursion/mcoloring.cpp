#include<iostream>
using namespace std;
bool isSafe(int node,int colors[],int col, bool graph[101][101],int n){
    for(int k=0;k<n;k++){
        if(k!=node && graph[k][node]==1 && colors[k]==col)
        return false;
    }
    return true;
}
bool solve(bool graph[101][101],int n,int m,int node,int colors[]){
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isSafe(node,colors,i,graph,n)==true){
            colors[node]=i;
            if(solve(graph,n,m,node+1,colors))
            return true;
            colors[node]=0;
        }
    }
    return false;
}
bool graphColor(bool graph[101][101],int m,int n){
    int colors[n]={0};
    if(solve(graph,n,m,0,colors))
    return true;
    return false;
}
int main(){
    int n, m, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of colors: ";
    cin >> m;
    cout << "Enter number of edges: ";
    cin >> e;
    bool graph[101][101] = {0};
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;   // Undirected graph
    }
    if (graphColor(graph, m, n))
        cout << "Graph can be colored using " << m << " colors.\n";
    else
        cout << "Graph cannot be colored using " << m << " colors.\n";

    return 0;
}

