// monotonic_queue_sliding_window_max: max value of every window of size k
// topic: medium/monotonic-queue — deque keeping window max
// problem: LeetCode 239. Sliding Window Maximum
// links:
//   https://leetcode.com/problems/sliding-window-maximum/
//   https://leetcode.cn/problems/sliding-window-maximum/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Sliding Window Maximum
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/sliding-window-maximum/solution/

#include <bits/stdc++.h>
using namespace std;

// Deque keeps candidate indices with decreasing values; front is the window max.
class Solution {
public:
    vector<int> solve(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < (int)nums.size(); ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (dq.front() <= i - k)
                dq.pop_front();
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

int main() {
    // input: n k \n a[0] ... a[n-1]   (1 <= k <= n)
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    vector<int> ans = sol.solve(a, k);
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i] << (i + 1 == (int)ans.size() ? "\n" : " ");
    return 0;
}
