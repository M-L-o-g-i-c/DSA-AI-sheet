// divide_conquer_max_subarray: max subarray sum via left/right/crossing recursion
// topic: tough/divide-and-conquer — maximum subarray (D&C)
// problem: LeetCode 53. Maximum Subarray
// links:
//   https://leetcode.com/problems/maximum-subarray/
//   https://leetcode.cn/problems/maximum-subarray/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Maximum Subarray
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/maximum-subarray/solution/

#include <bits/stdc++.h>
using namespace std;

// Best subarray is entirely left, entirely right, or crosses the midpoint.
class Solution {
public:
    int solve(vector<int>& nums) {
        function<int(int, int)> helper = [&](int lo, int hi) -> int {
            if (hi - lo == 1) return nums[lo];
            int mid = lo + (hi - lo) / 2;
            int left = helper(lo, mid);    // best in left half
            int right = helper(mid, hi);   // best in right half
            // best crossing mid: max left suffix + max right prefix
            int sum = 0, leftSum = INT_MIN;
            for (int i = mid - 1; i >= lo; i--) {
                sum += nums[i];
                leftSum = max(leftSum, sum);
            }
            sum = 0;
            int rightSum = INT_MIN;
            for (int i = mid; i < hi; i++) {
                sum += nums[i];
                rightSum = max(rightSum, sum);
            }
            return max({left, right, leftSum + rightSum});
        };
        return helper(0, (int)nums.size());
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
