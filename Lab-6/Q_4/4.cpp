#include<bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);
    queue<int> q;
    int visited = 0;

    for (int u = 0; u < V; u++) {
        for (auto v : adj[u]) {
            inDegree[v]++;
        }
    }

    for (int u = 0; u < V; u++) {
        if (inDegree[u] == 0) {
            q.push(u);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited++;

        for (auto v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return visited != V;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    int edges;
    cin >> edges;

    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (isCyclic(n, adj)) {
        cout << "Graph contains cycle." << endl;
    } else {
        cout << "Graph does not contain cycle." << endl;
    }

    return 0;
}
