// directed_graph_basic: how it works — adjacency list build + print
// topic: medium/directed-graphs — how it works (adjacency list)
// problem: demo — build and print the adjacency list of a directed graph
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

// Directed edge u -> v is stored only in adj[u].
class Solution {
public:
    vector<vector<int>> solve(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) adj[e[0]].push_back(e[1]);
        return adj;
    }
};

int main() {
    // input: n m \n m edges "u v" (0-indexed, directed u -> v)
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> edges(m, vector<int>(2));
    for (auto& e : edges) cin >> e[0] >> e[1];
    Solution sol;
    vector<vector<int>> adj = sol.solve(n, edges);
    for (int u = 0; u < n; u++) {
        cout << u << ":";
        for (int v : adj[u]) cout << " " << v;
        cout << "\n";
    }
    return 0;
}
