// topological_sort_basic: how it works — Kahn's algorithm vs DFS reverse postorder
// topic: tough/topological-sort — how it works (Kahn vs DFS)
// problem: demo — topological order of a DAG by Kahn's and by DFS
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Topological Sorting
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/graph/topological-sort.html

#include <bits/stdc++.h>
using namespace std;

// Kahn: repeatedly take a node with indegree 0 (BFS on the DAG).
// DFS: reverse postorder of finish times. Either order is empty on a cycle.
class Solution {
public:
    pair<vector<int>, vector<int>> solve(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }

        // Kahn's algorithm
        queue<int> q;
        for (int u = 0; u < n; u++)
            if (indeg[u] == 0) q.push(u);
        vector<int> kahn;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            kahn.push_back(u);
            for (int v : adj[u])
                if (--indeg[v] == 0) q.push(v);
        }
        if ((int)kahn.size() != n) kahn.clear();

        // DFS reverse postorder
        vector<int> color(n, 0);
        vector<int> post;
        bool cycle = false;
        function<void(int)> dfs = [&](int u) {
            color[u] = 1;
            for (int v : adj[u]) {
                if (color[v] == 1) {
                    cycle = true;
                    return;
                }
                if (color[v] == 0) dfs(v);
            }
            color[u] = 2;
            post.push_back(u);
        };
        for (int u = 0; u < n; u++)
            if (color[u] == 0 && !cycle) dfs(u);
        vector<int> dfsOrder(post.rbegin(), post.rend());
        if (cycle) dfsOrder.clear();

        return {kahn, dfsOrder};
    }
};

int main() {
    // input: n m \n m edges "u v" (0-indexed, edge u -> v means u before v)
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> edges(m, vector<int>(2));
    for (auto& e : edges) cin >> e[0] >> e[1];
    Solution sol;
    auto orders = sol.solve(n, edges);
    auto print = [](const vector<int>& order) {
        if (order.empty()) {
            cout << "cycle\n";
            return;
        }
        for (size_t i = 0; i < order.size(); i++) {
            if (i) cout << " ";
            cout << order[i];
        }
        cout << "\n";
    };
    print(orders.first);
    print(orders.second);
    return 0;
}
