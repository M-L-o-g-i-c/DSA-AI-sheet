// undirected_graph_cycle: undirected cycle detection with DFS parent tracking
// topic: medium/undirected-graphs — cycle detection (DFS parent)
// problem: demo — whether the undirected graph contains a cycle
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Checking a graph for acyclicity and finding a cycle in O(M)
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/graph/finding-cycle.html

#include <bits/stdc++.h>
using namespace std;

// A visited neighbor that is not the DFS parent of u closes a cycle.
class Solution {
    bool dfs(int u, int parent, const vector<vector<int>>& adj, vector<char>& vis) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                if (dfs(v, u, adj, vis)) return true;
            } else if (v != parent) {
                return true;
            }
        }
        return false;
    }

public:
    bool solve(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<char> vis(n, false);
        for (int u = 0; u < n; u++)
            if (!vis[u] && dfs(u, -1, adj, vis)) return true;
        return false;
    }
};

int main() {
    // input: n m \n m edges "u v" (0-indexed, undirected, no parallel edges)
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> edges(m, vector<int>(2));
    for (auto& e : edges) cin >> e[0] >> e[1];
    Solution sol;
    cout << (sol.solve(n, edges) ? 1 : 0) << "\n";
    return 0;
}
