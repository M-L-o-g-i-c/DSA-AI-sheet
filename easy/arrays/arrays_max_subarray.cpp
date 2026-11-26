// arrays_max_subarray: maximum sum of a contiguous subarray (Kadane)
// topic: easy/arrays — Kadane's algorithm
// problem: LeetCode 53. Maximum Subarray
// links:   https://leetcode.com/problems/maximum-subarray/
//          https://leetcode.cn/problems/maximum-subarray/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 53. Maximum Subarray - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/maximum-subarray/solution/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // cur is the best sum ending here; restart from nums[i] when cur turns negative.
    int solve(vector<int>& nums) {
        int best = nums[0], cur = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]);
            best = max(best, cur);
        }
        return best;
    }
};

int main() {
    // input: n \n nums[0] ... nums[n-1]   (n >= 1)
    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (auto& v : nums) cin >> v;
    Solution sol;
    // output: max subarray sum
    cout << sol.solve(nums) << "\n";
    return 0;
}
