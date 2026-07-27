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



//Adjacency matrix
/*
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v]=1;
        adj[v][u]=1;   // Remove this line for directed graph
    }
    cout << "Adjacency Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}*/

//Weighted graph
/*
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});   // Remove for directed graph
    }
    return 0;
}*/