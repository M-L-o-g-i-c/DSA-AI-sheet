// monotonic_stack_largest_rectangle: largest rectangle area in a histogram
// topic: medium/monotonic-stack — increasing stack with sentinel
// problem: LeetCode 84. Largest Rectangle in Histogram
// links:
//   https://leetcode.com/problems/largest-rectangle-in-histogram/
//   https://leetcode.cn/problems/largest-rectangle-in-histogram/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Largest Rectangle in Histogram
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/largest-rectangle-in-histogram/solution/

#include <bits/stdc++.h>
using namespace std;

// Increasing stack of indices; each bar is the height of the rectangle it bounds.
// The sentinel bar of height 0 flushes the stack at the end.
class Solution {
public:
    int solve(vector<int>& heights) {
        int n = (int)heights.size();
        stack<int> st;
        int best = 0;
        for (int i = 0; i <= n; ++i) {
            int h = (i == n) ? 0 : heights[i];
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                best = max(best, height * (i - left - 1));
            }
            st.push(i);
        }
        return best;
    }
};

int main() {
    // input: n \n h[0] ... h[n-1]
    int n;
    if (!(cin >> n)) return 0;
    vector<int> h(n);
    for (auto& v : h) cin >> v;
    Solution sol;
    cout << sol.solve(h) << "\n";
    return 0;
}
