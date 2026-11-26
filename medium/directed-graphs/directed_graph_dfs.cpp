// directed_graph_dfs: DFS preorder traversal from a source on a digraph
// topic: medium/directed-graphs — DFS traversal
// problem: demo — DFS preorder from s (list membership = reachability)
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Depth First Search
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/graph/depth-first-search.html

#include <bits/stdc++.h>
using namespace std;

// Recursive DFS: visit u, then each unvisited out-neighbor in order.
class Solution {
    void dfs(int u, const vector<vector<int>>& adj, vector<char>& vis, vector<int>& order) {
        vis[u] = true;
        order.push_back(u);
        for (int v : adj[u])
            if (!vis[v]) dfs(v, adj, vis, order);
    }

public:
    vector<int> solve(int n, const vector<vector<int>>& edges, int s) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) adj[e[0]].push_back(e[1]);
        vector<char> vis(n, false);
        vector<int> order;
        dfs(s, adj, vis, order);
        return order;
    }
};

int main() {
    // input: n m \n m edges "u v" (0-indexed, directed u -> v) \n s
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> edges(m, vector<int>(2));
    for (auto& e : edges) cin >> e[0] >> e[1];
    int s;
    cin >> s;
    Solution sol;
    vector<int> order = sol.solve(n, edges, s);
    for (size_t i = 0; i < order.size(); i++) {
        if (i) cout << " ";
        cout << order[i];
    }
    cout << "\n";
    return 0;
}
