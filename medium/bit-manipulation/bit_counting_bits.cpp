// bit_counting_bits: count 1-bits of every i in 0..n with DP
// topic: medium/bit-manipulation — DP on bits (i >> 1)
// problem: LeetCode 338. Counting Bits
// links:
//   https://leetcode.com/problems/counting-bits/
//   https://leetcode.cn/problems/counting-bits/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Counting Bits
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/counting-bits/solution/

#include <bits/stdc++.h>
using namespace std;

// dp[i] = dp[i >> 1] + (i & 1): reuse the count of i without its lowest bit.
class Solution {
public:
    vector<int> solve(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            dp[i] = dp[i >> 1] + (i & 1);
        return dp;
    }
};

int main() {
    // input: n   (count 1-bits for every i in 0..n)
    int n;
    if (!(cin >> n)) return 0;
    Solution sol;
    vector<int> ans = sol.solve(n);
    for (int i = 0; i <= n; ++i) cout << ans[i] << (i == n ? "\n" : " ");
    return 0;
}
