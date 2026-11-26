// union_find_provinces: count provinces with DSU
// topic: tough/union-find — provinces (DSU)
// problem: LeetCode 547. Number of Provinces
// links:   https://leetcode.com/problems/number-of-provinces/
//          https://leetcode.cn/problems/number-of-provinces/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 547. Number of Provinces - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/number-of-provinces/solution/

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
    int solve(vector<vector<int>>& isConnected) {
        int n = (int)isConnected.size();
        DSU dsu(n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (isConnected[i][j]) dsu.unite(i, j);
        int provinces = 0;
        for (int i = 0; i < n; i++)
            if (dsu.find(i) == i) provinces++;
        return provinces;
    }
};

int main() {
    // input: n \n n x n matrix isConnected (0/1)
    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> isConnected(n, vector<int>(n));
    for (auto& row : isConnected)
        for (auto& x : row) cin >> x;
    Solution sol;
    cout << sol.solve(isConnected) << "\n";
    return 0;
}
