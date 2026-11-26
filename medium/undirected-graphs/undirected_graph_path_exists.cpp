// undirected_graph_path_exists: BFS reachability between two nodes
// topic: medium/undirected-graphs — path existence (BFS)
// problem: LeetCode 1971. Find if Path Exists in Graph
// links:   https://leetcode.com/problems/find-if-path-exists-in-graph/
//          https://leetcode.cn/problems/find-if-path-exists-in-graph/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 1971. Find if Path Exists in Graph - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/find-if-path-exists-in-graph/solution/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<char> vis(n, false);
        queue<int> q;
        vis[source] = true;
        q.push(source);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == destination) return true;
            for (int v : adj[u])
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
        }
        return false;
    }
};

int main() {
    // input: n m \n m edges "u v" (0-indexed, undirected) \n source destination
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> edges(m, vector<int>(2));
    for (auto& e : edges) cin >> e[0] >> e[1];
    int source, destination;
    cin >> source >> destination;
    Solution sol;
    cout << (sol.solve(n, edges, source, destination) ? 1 : 0) << "\n";
    return 0;
}
