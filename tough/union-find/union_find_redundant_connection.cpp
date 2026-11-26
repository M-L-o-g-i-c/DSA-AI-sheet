// union_find_redundant_connection: find the redundant edge with DSU
// topic: tough/union-find — redundant connection (DSU)
// problem: LeetCode 684. Redundant Connection
// links:   https://leetcode.com/problems/redundant-connection/
//          https://leetcode.cn/problems/redundant-connection/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 684. Redundant Connection - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/redundant-connection/solution/

#include <bits/stdc++.h>
using namespace std;

// Reusable DSU: parent[x] < 0 means x is a root and -parent[x] is its size.
class DSU {
    vector<int> parent;

public:
    explicit DSU(int n) : parent(n, -1) {}

    int find(int x) {
        if (parent[x] < 0) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    bool connected(int a, int b) { return find(a) == find(b); }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (parent[a] > parent[b]) swap(a, b); // union by size
        parent[a] += parent[b];
        parent[b] = a;
    }
};

class Solution {
public:
    vector<int> solve(vector<vector<int>>& edges) {
        int n = (int)edges.size(); // nodes are 1..n
        DSU dsu(n + 1);
        for (const auto& e : edges) {
            if (dsu.connected(e[0], e[1])) return e;
            dsu.unite(e[0], e[1]);
        }
        return {};
    }
};

int main() {
    // input: m \n m edges "u v" (1-indexed; exactly one edge is redundant)
    int m;
    if (!(cin >> m)) return 0;
    vector<vector<int>> edges(m, vector<int>(2));
    for (auto& e : edges) cin >> e[0] >> e[1];
    Solution sol;
    vector<int> ans = sol.solve(edges);
    cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}
