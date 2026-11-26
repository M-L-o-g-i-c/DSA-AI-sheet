// dp_lis: longest increasing subsequence via patience tails array
// topic: tough/dynamic-programming — LIS (O(n log n))
// problem: LeetCode 300. Longest Increasing Subsequence
// links:
//   https://leetcode.com/problems/longest-increasing-subsequence/
//   https://leetcode.cn/problems/longest-increasing-subsequence/
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Longest Increasing Subsequence
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/sequences/longest_increasing_subsequence.html

#include <bits/stdc++.h>
using namespace std;

// tails[k] = smallest tail of all increasing subsequences of length k+1.
// Growing tails is strictly increasing, so its size is the LIS length.
// O(n^2) alternative: dp[i] = 1 + max(dp[j]) over j < i with a[j] < a[i].
class Solution {
public:
    int solve(vector<int>& nums) {
        vector<int> tails;
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x);
            else *it = x;
        }
        return (int)tails.size();
    }
};

int main() {
    // input: n \n nums[0] ... nums[n-1]
    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (auto& v : nums) cin >> v;
    Solution sol;
    cout << sol.solve(nums) << "\n";
    return 0;
}
