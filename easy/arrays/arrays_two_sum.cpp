// arrays_two_sum: find two indices whose values add up to target
// topic: easy/arrays — hash map (two sum)
// problem: LeetCode 1. Two Sum
// links:   https://leetcode.com/problems/two-sum/
//          https://leetcode.cn/problems/two-sum/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 1. Two Sum - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/two-sum/solution/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // map stores value -> index seen so far; one pass, O(n).
    vector<int> solve(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int j = 0; j < (int)nums.size(); j++) {
            int need = target - nums[j];
            auto it = seen.find(need);
            if (it != seen.end()) return {it->second, j};
            seen[nums[j]] = j;
        }
        return {}; // guaranteed unreachable: exactly one valid pair exists
    }
};

int main() {
    // input: n target \n nums[0] ... nums[n-1]   (exactly one valid pair)
    int n, target;
    if (!(cin >> n >> target)) return 0;
    vector<int> nums(n);
    for (auto& v : nums) cin >> v;
    Solution sol;
    vector<int> ans = sol.solve(nums, target);
    // output: i j
    cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}
