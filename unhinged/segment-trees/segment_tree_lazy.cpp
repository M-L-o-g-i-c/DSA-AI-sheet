// segment_tree_lazy: lazy propagation with range add and range sum query
// topic: unhinged/segment-trees — lazy propagation (range add / range sum)
// problem: demo — range add updates with range sum queries
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

// lazy[v] holds an addition that applies to every element of node v but has
// not been pushed to its children yet; push() materializes it on the way down.
class Solution {
    vector<long long> t, lazy;

    void build(const vector<long long>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void push(int v, int tl, int tr) {
        if (lazy[v] == 0) return;
        int tm = (tl + tr) / 2;
        t[v * 2] += lazy[v] * (tm - tl + 1);
        lazy[v * 2] += lazy[v];
        t[v * 2 + 1] += lazy[v] * (tr - tm);
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }

    void range_add(int v, int tl, int tr, int l, int r, long long val) {
        if (l > r) return;
        if (l == tl && r == tr) {
            t[v] += val * (tr - tl + 1);
            lazy[v] += val;
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            range_add(v * 2, tl, tm, l, min(r, tm), val);
            range_add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    long long query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return t[v];
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm))
             + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

public:
    // ops: type 1 l r v adds v to a[l..r]; type 2 l r returns sum of a[l..r].
    vector<long long> solve(const vector<long long>& a, const vector<vector<long long>>& ops) {
        int n = (int)a.size();
        t.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(a, 1, 0, n - 1);
        vector<long long> ans;
        for (const auto& op : ops) {
            if (op[0] == 1) range_add(1, 0, n - 1, (int)op[1], (int)op[2], op[3]);
            else ans.push_back(query(1, 0, n - 1, (int)op[1], (int)op[2]));
        }
        return ans;
    }
};

int main() {
    // input: n q \n a[0] ... a[n-1] \n q lines:
    //   "1 l r v" adds v to a[l..r] | "2 l r" asks sum of a[l..r] (0-based, inclusive)
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> a(n);
    for (auto& v : a) cin >> v;
    vector<vector<long long>> ops;
    for (int i = 0; i < q; i++) {
        long long type;
        cin >> type;
        if (type == 1) {
            long long l, r, v;
            cin >> l >> r >> v;
            ops.push_back({type, l, r, v});
        } else {
            long long l, r;
            cin >> l >> r;
            ops.push_back({type, l, r});
        }
    }
    Solution sol;
    for (long long x : sol.solve(a, ops)) cout << x << "\n";
    return 0;
}
