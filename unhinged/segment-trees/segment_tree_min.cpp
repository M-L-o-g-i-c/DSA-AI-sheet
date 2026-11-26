// segment_tree_min: range minimum query with point update
// topic: unhinged/segment-trees — range minimum + point update
// problem: demo — range minimum queries with point assignments
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Segment Tree
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/data_structures/segment_tree.html

#include <bits/stdc++.h>
using namespace std;

// Same shape as a sum tree, but nodes combine with min instead of +.
class Solution {
    vector<long long> t;

    void build(const vector<long long>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }

    void update(int v, int tl, int tr, int pos, long long val) {
        if (tl == tr) {
            t[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(v * 2, tl, tm, pos, val);
            else update(v * 2 + 1, tm + 1, tr, pos, val);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }

    long long query(int v, int tl, int tr, int l, int r) {
        if (l > r) return LLONG_MAX; // identity of min
        if (l == tl && r == tr) return t[v];
        int tm = (tl + tr) / 2;
        return min(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

public:
    // ops: type 1 i v sets a[i] = v; type 2 l r returns min of a[l..r].
    vector<long long> solve(const vector<long long>& a, const vector<vector<long long>>& ops) {
        int n = (int)a.size();
        t.assign(4 * n, LLONG_MAX);
        build(a, 1, 0, n - 1);
        vector<long long> ans;
        for (const auto& op : ops) {
            if (op[0] == 1) update(1, 0, n - 1, (int)op[1], op[2]);
            else ans.push_back(query(1, 0, n - 1, (int)op[1], (int)op[2]));
        }
        return ans;
    }
};

int main() {
    // input: n q \n a[0] ... a[n-1] \n q lines: "1 i v" sets a[i]=v | "2 l r" asks min of a[l..r]
    // (0-based indices, l and r inclusive)
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> a(n);
    for (auto& v : a) cin >> v;
    vector<vector<long long>> ops(q, vector<long long>(3));
    for (auto& op : ops) cin >> op[0] >> op[1] >> op[2];
    Solution sol;
    for (long long x : sol.solve(a, ops)) cout << x << "\n";
    return 0;
}
