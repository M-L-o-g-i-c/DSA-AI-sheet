// undirected_graph_components: count connected components with DFS
// topic: medium/undirected-graphs — connected components
// problem: demo — number of connected components of an undirected graph
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Search for connected components in a graph
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/graph/search-for-connected-components.html

#include <bits/stdc++.h>
using namespace std;

// Each DFS started from an unvisited node floods exactly one component.
class Solution {
    void dfs(int u, const vector<vector<int>>& adj, vector<char>& vis) {
        vis[u] = true;
        for (int v : adj[u])
            if (!vis[v]) dfs(v, adj, vis);
    }

public:
    int solve(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<char> vis(n, false);
        int components = 0;
        for (int u = 0; u < n; u++) {
            if (!vis[u]) {
                dfs(u, adj, vis);
                components++;
            }
        }
        return components;
    }
};

int main() {
    // input: n m \n m edges "u v" (0-indexed, undirected)
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> edges(m, vector<int>(2));
    for (auto& e : edges) cin >> e[0] >> e[1];
    Solution sol;
    cout << sol.solve(n, edges) << "\n";
    return 0;
}
