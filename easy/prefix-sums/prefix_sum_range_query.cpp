// prefix_sum_range_query: O(1) range-sum queries over an immutable prefix array
// topic: easy/prefix-sums — immutable range sum query
// problem: LeetCode 303. Range Sum Query - Immutable
// links:   https://leetcode.com/problems/range-sum-query-immutable/
//          https://leetcode.cn/problems/range-sum-query-immutable/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 303. Range Sum Query - Immutable - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/range-sum-query-immutable/solution/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // prefix[i] = sum of a[0..i-1], so one query is O(1).
    int solve(const vector<int>& prefix, int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

int main() {
    // input: n \n prefix[0] ... prefix[n] \n q \n then q lines of left right
    // (prefix[i] = sum of a[0..i-1], so prefix has n+1 entries; 0 <= left <= right < n)
    int n;
    if (!(cin >> n)) return 0;
    vector<int> prefix(n + 1);
    for (auto& v : prefix) cin >> v;
    int q;
    cin >> q;
    Solution sol;
    // output: one range sum per line
    while (q--) {
        int left, right;
        cin >> left >> right;
        cout << sol.solve(prefix, left, right) << "\n";
    }
    return 0;
}
