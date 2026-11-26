// sliding_window_min_size_sum: shortest subarray with sum >= target
// topic: medium/sliding-window — variable window (min length)
// problem: LeetCode 209. Minimum Size Subarray Sum
// links:
//   https://leetcode.com/problems/minimum-size-subarray-sum/
//   https://leetcode.cn/problems/minimum-size-subarray-sum/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Minimum Size Subarray Sum
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/minimum-size-subarray-sum/solution/

#include <bits/stdc++.h>
using namespace std;

// Grow hi until sum >= target, then shrink lo to get the shortest valid window.
class Solution {
public:
    int solve(int target, vector<int>& nums) {
        long long sum = 0;
        int best = INT_MAX, lo = 0;
        for (int hi = 0; hi < (int)nums.size(); ++hi) {
            sum += nums[hi];
            while (sum >= target) {
                best = min(best, hi - lo + 1);
                sum -= nums[lo++];
            }
        }
        return best == INT_MAX ? 0 : best;
    }
};

int main() {
    // input: target n \n a[0] ... a[n-1]   (a[i] > 0)
    int target, n;
    if (!(cin >> target >> n)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    cout << sol.solve(target, a) << "\n";
    return 0;
}
