// directed_graph_cycle: directed cycle detection with DFS colors
// topic: medium/directed-graphs — cycle detection (DFS colors)
// problem: demo — whether the digraph contains a directed cycle
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

// Colors: 0 = unvisited, 1 = on the DFS stack, 2 = done.
// An edge to a gray node is a back edge, i.e. a cycle.
class Solution {
    bool dfs(int u, const vector<vector<int>>& adj, vector<int>& color) {
        color[u] = 1;
        for (int v : adj[u]) {
            if (color[v] == 1) return true;
            if (color[v] == 0 && dfs(v, adj, color)) return true;
        }
        color[u] = 2;
        return false;
    }

public:
    bool solve(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) adj[e[0]].push_back(e[1]);
        vector<int> color(n, 0);
        for (int u = 0; u < n; u++)
            if (color[u] == 0 && dfs(u, adj, color)) return true;
        return false;
    }
};

int main() {
    // input: n m \n m edges "u v" (0-indexed, directed u -> v)
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> edges(m, vector<int>(2));
    for (auto& e : edges) cin >> e[0] >> e[1];
    Solution sol;
    cout << (sol.solve(n, edges) ? 1 : 0) << "\n";
    return 0;
}
