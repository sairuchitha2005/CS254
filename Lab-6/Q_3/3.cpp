#include <bits/stdc++.h>
using namespace std;

bool dfs(int curr, int des, vector<vector<int>>& adj, vector<int>& vis) {
    if (curr == des) {
        return true;
    }
    vis[curr] = 1;
    for (int x : adj[curr]) {
        if (!vis[x] && dfs(x, des, adj, vis)) {
            return true;
        }
    }
    return false;
}

bool isPath(int src, int des, vector<vector<int>>& adj) {
    vector<int> vis(adj.size() + 1, 0);
    return dfs(src, des, adj, vis);
}

vector<vector<int>> findSCC(int n, vector<vector<int>>& a) {
    vector<vector<int>> ans;
    vector<int> is_scc(n + 1, 0);
    vector<vector<int>> adj(n + 1);

    // Constructing adjacency list
    for (auto& edge : a) {
        adj[edge[0]].push_back(edge[1]);
    }

    // Traversing all the vertices
    for (int i = 1; i <= n; i++) {
        if (!is_scc[i]) {
            vector<int> scc;
            scc.push_back(i);

            // Check for other vertices whether they can be part of the current SCC
            for (int j = i + 1; j <= n; j++) {
                if (!is_scc[j] && isPath(i, j, adj) && isPath(j, i, adj)) {
                    is_scc[j] = 1;
                    scc.push_back(j);
                }
            }

            ans.push_back(scc); // Insert the SCC containing vertex i into the final list.
        }
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int V;
    cin >> V;

    // Read edges from input.txt
    vector<vector<int>> edges;
    int u, v;
    while (cin >> u >> v) {
        edges.push_back({u, v});
    }

    vector<vector<int>> ans = findSCC(V, edges);

    cout << "Strongly Connected Components are:\n";
    for (auto& scc : ans) {
        for (int vertex : scc) {
            cout << vertex << " ";
        }
        cout << "\n";
    }

    return 0;
}
