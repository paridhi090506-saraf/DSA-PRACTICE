#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> visited(V, 0);

    pq.push({0,0});

    int sum = 0;

    while(!pq.empty()) {

        auto it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;

        if(visited[node] == 1)
            continue;

        visited[node] = 1;

        sum += wt;

        for(auto it : adj[node]) {

            int adjNode = it[0];
            int edgeWt = it[1];

            if(!visited[adjNode]) {
                pq.push({edgeWt, adjNode});
            }
        }
    }

    return sum;
}

int main() {

    int V = 3;

    vector<vector<int>> adj[V];

    // 0 --1-- 1
    adj[0].push_back({1,1});
    adj[1].push_back({0,1});

    // 0 --4-- 2
    adj[0].push_back({2,4});
    adj[2].push_back({0,4});

    // 1 --2-- 2
    adj[1].push_back({2,2});
    adj[2].push_back({1,2});

    int ans = spanningTree(V, adj);

    cout << "MST Weight = " << ans;

    return 0;
}