// union_find_dsu: full DSU class (find/connected/unite) reused in problems
// topic: tough/union-find — DSU class
// problem: demo — count connected components with a reusable DSU class
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Disjoint Set Union
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/data_structures/disjoint_set_union.html

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
    int solve(int n, const vector<vector<int>>& edges) {
        DSU dsu(n);
        for (const auto& e : edges) dsu.unite(e[0], e[1]);
        int components = 0;
        for (int u = 0; u < n; u++)
            if (dsu.find(u) == u) components++;
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
