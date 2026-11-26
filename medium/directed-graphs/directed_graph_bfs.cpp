// directed_graph_bfs: BFS shortest distances on an unweighted digraph
// topic: medium/directed-graphs — BFS shortest path
// problem: demo — shortest distance from s to every node (unreachable = -1)
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Breadth-first search
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/graph/breadth-first-search.html

#include <bits/stdc++.h>
using namespace std;

// On unit weights the first time a node is reached is its shortest distance.
class Solution {
public:
    vector<int> solve(int n, const vector<vector<int>>& edges, int s) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) adj[e[0]].push_back(e[1]);
        vector<int> dist(n, -1);
        queue<int> q;
        dist[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
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
    vector<int> dist = sol.solve(n, edges, s);
    for (size_t i = 0; i < dist.size(); i++) {
        if (i) cout << " ";
        cout << dist[i];
    }
    cout << "\n";
    return 0;
}
