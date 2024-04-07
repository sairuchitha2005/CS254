#include <bits/stdc++.h>
using namespace std;

vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n, -1);
        vector<vector<vector<int>>> graph(2, vector<vector<int>>(n));
        for(vector<int>& rE: redEdges)
            graph[0][rE[0]].push_back(rE[1]);
        for(vector<int>& bE: blueEdges)
            graph[1][bE[0]].push_back(bE[1]);
        queue<pair<int, bool>> q;
        q.push({0, true});
        q.push({0, false});
        int path = 0, size , u;
        bool col;
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        while(!q.empty()) {
            size = q.size();
            while(size--) {
                u = q.front().first;
                col = q.front().second;
                q.pop();
                if(visited[col][u])
                    continue;
                visited[col][u] = true;
                if(ans[u] == -1)
                    ans[u] = path;
                for(int v: graph[!col][u])
                    if(!visited[!col][v])
                        q.push({v, !col});
            }
            path++;
        }
        return ans;
    }

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n; // Read the number of nodes
    
    int red_edge_count;
    cin >> red_edge_count; // Read the number of red edges
    vector<vector<int>> red_edges(red_edge_count, vector<int>(2));
    for (int i = 0; i < red_edge_count; ++i) {
        cin >> red_edges[i][0] >> red_edges[i][1]; // Read red edges
    }
    
    int blue_edge_count;
    cin >> blue_edge_count; // Read the number of blue edges
    vector<vector<int>> blue_edges(blue_edge_count, vector<int>(2));
    for (int i = 0; i < blue_edge_count; ++i) {
        cin >> blue_edges[i][0] >> blue_edges[i][1]; // Read blue edges
    }

    vector<int> result = shortestAlternatingPaths(n, red_edges, blue_edges);

    // Output the result
    cout << "Shortest alternating paths: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
