// monotonic_stack_daily_temperatures: days until a warmer temperature
// topic: medium/monotonic-stack — monotonic decreasing stack (indices)
// problem: LeetCode 739. Daily Temperatures
// links:
//   https://leetcode.com/problems/daily-temperatures/
//   https://leetcode.cn/problems/daily-temperatures/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Daily Temperatures
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/daily-temperatures/solution/

#include <bits/stdc++.h>
using namespace std;

// Stack holds indices of still-colder days; a warmer day resolves all it beats.
class Solution {
public:
    vector<int> solve(vector<int>& temperatures) {
        int n = (int)temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    // input: n \n t[0] ... t[n-1]
    int n;
    if (!(cin >> n)) return 0;
    vector<int> t(n);
    for (auto& v : t) cin >> v;
    Solution sol;
    vector<int> ans = sol.solve(t);
    for (int i = 0; i < n; ++i) cout << ans[i] << (i + 1 == n ? "\n" : " ");
    return 0;
}
