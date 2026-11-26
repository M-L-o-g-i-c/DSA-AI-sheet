// sliding_window_max_average: maximum average of any length-k subarray
// topic: medium/sliding-window — fixed window sum
// problem: LeetCode 643. Maximum Average Subarray I
// links:
//   https://leetcode.com/problems/maximum-average-subarray-i/
//   https://leetcode.cn/problems/maximum-average-subarray-i/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Maximum Average Subarray I
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/maximum-average-subarray-i/solution/

#include <bits/stdc++.h>
using namespace std;

// One pass over fixed windows of size k; track the largest sum, divide by k at the end.
class Solution {
public:
    double solve(vector<int>& nums, int k) {
        long long sum = 0;
        for (int i = 0; i < k; ++i) sum += nums[i];
        long long best = sum;
        for (int i = k; i < (int)nums.size(); ++i) {
            sum += nums[i] - nums[i - k];
            best = max(best, sum);
        }
        return (double)best / k;
    }
};

int main() {
    // input: n k \n a[0] ... a[n-1]   (1 <= k <= n)
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    cout << fixed << setprecision(5) << sol.solve(a, k) << "\n";
    return 0;
}
