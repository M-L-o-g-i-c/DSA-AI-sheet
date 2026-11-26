// union_find_basic: how it works — find/union, path compression, union by size
// topic: tough/union-find — how it works (find/union)
// problem: demo — connectivity queries after a batch of unions
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

// parent[x] < 0 means x is a root and -parent[x] is its component size.
class Solution {
    int find(vector<int>& parent, int x) {
        if (parent[x] < 0) return x;
        return parent[x] = find(parent, parent[x]); // path compression
    }

    void unite(vector<int>& parent, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);
        if (a == b) return;
        if (parent[a] > parent[b]) swap(a, b); // union by size: |a| >= |b|
        parent[a] += parent[b];
        parent[b] = a;
    }

public:
    vector<int> solve(int n, const vector<vector<int>>& unions, const vector<vector<int>>& queries) {
        vector<int> parent(n, -1);
        for (const auto& e : unions) unite(parent, e[0], e[1]);
        vector<int> ans;
        for (const auto& q : queries)
            ans.push_back(find(parent, q[0]) == find(parent, q[1]) ? 1 : 0);
        return ans;
    }
};

int main() {
    // input: n m q \n m lines "u v" (unite) \n q lines "u v" (connected?)
    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    vector<vector<int>> unions(m, vector<int>(2));
    for (auto& e : unions) cin >> e[0] >> e[1];
    vector<vector<int>> queries(q, vector<int>(2));
    for (auto& e : queries) cin >> e[0] >> e[1];
    Solution sol;
    vector<int> ans = sol.solve(n, unions, queries);
    for (size_t i = 0; i < ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}
