//2 ways: adjacency matrix and adjacency list
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // Remove this line for directed graph
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int node : adj[i])
            cout << node << " ";
        cout << endl;
    }
    return 0;
}