// prefix_sum_basic: build a 1D prefix array and answer range sums in O(1)
// topic: easy/prefix-sums — 1D prefix build + range sum
// problem: demo — prefix[i] = sum of a[0..i-1]; range sum a[l..r] in O(1)
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // prefix[i] = sum of a[0..i-1]; then sum a[l..r] = prefix[r+1] - prefix[l].
    vector<long long> solve(const vector<int>& a, const vector<vector<int>>& queries) {
        int n = (int)a.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + a[i];
        vector<long long> ans;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(prefix[r + 1] - prefix[l]);
        }
        return ans;
    }
};

int main() {
    // input: n q \n a[0] ... a[n-1] \n then q lines of l r   (0 <= l <= r < n)
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    vector<vector<int>> queries(q, vector<int>(2));
    for (auto& query : queries) cin >> query[0] >> query[1];
    Solution sol;
    // output: one range sum per line
    for (long long s : sol.solve(a, queries)) cout << s << "\n";
    return 0;
}
