// undirected_graph_basic: how it works — adjacency list + DFS/BFS orders
// topic: medium/undirected-graphs — how it works (adjacency list, DFS/BFS)
// problem: demo — DFS preorder and BFS order from source s
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

// Undirected edge u-v is stored in both adj[u] and adj[v].
// solve returns {DFS preorder, BFS order} from s.
class Solution {
    void dfs(int u, const vector<vector<int>>& adj, vector<char>& vis, vector<int>& order) {
        vis[u] = true;
        order.push_back(u);
        for (int v : adj[u])
            if (!vis[v]) dfs(v, adj, vis, order);
    }

public:
    pair<vector<int>, vector<int>> solve(int n, const vector<vector<int>>& edges, int s) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<char> vis(n, false);
        vector<int> dfsOrder;
        dfs(s, adj, vis, dfsOrder);
        vector<char> seen(n, false);
        vector<int> bfsOrder;
        queue<int> q;
        seen[s] = true;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            bfsOrder.push_back(u);
            for (int v : adj[u])
                if (!seen[v]) {
                    seen[v] = true;
                    q.push(v);
                }
        }
        return {dfsOrder, bfsOrder};
    }
};

int main() {
    // input: n m \n m edges "u v" (0-indexed, undirected) \n s
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> edges(m, vector<int>(2));
    for (auto& e : edges) cin >> e[0] >> e[1];
    int s;
    cin >> s;
    Solution sol;
    auto orders = sol.solve(n, edges, s);
    cout << "dfs:";
    for (int v : orders.first) cout << " " << v;
    cout << "\nbfs:";
    for (int v : orders.second) cout << " " << v;
    cout << "\n";
    return 0;
}
