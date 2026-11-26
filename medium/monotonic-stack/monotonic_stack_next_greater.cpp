// monotonic_stack_next_greater: next greater element for each query value
// topic: medium/monotonic-stack — monotonic decreasing stack
// problem: LeetCode 496. Next Greater Element I
// links:
//   https://leetcode.com/problems/next-greater-element-i/
//   https://leetcode.cn/problems/next-greater-element-i/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Next Greater Element I
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/next-greater-element-i/solution/

#include <bits/stdc++.h>
using namespace std;

// Resolve next greater for all of nums2 with one decreasing stack, then map nums1.
class Solution {
public:
    vector<int> solve(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;
        for (int x : nums2) {
            while (!st.empty() && st.top() < x) {
                nextGreater[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }
        vector<int> ans;
        for (int x : nums1) {
            auto it = nextGreater.find(x);
            ans.push_back(it == nextGreater.end() ? -1 : it->second);
        }
        return ans;
    }
};

int main() {
    // input: n1 n2 \n nums1[0] ... nums1[n1-1] \n nums2[0] ... nums2[n2-1]
    int n1, n2;
    if (!(cin >> n1 >> n2)) return 0;
    vector<int> a(n1), b(n2);
    for (auto& v : a) cin >> v;
    for (auto& v : b) cin >> v;
    Solution sol;
    vector<int> ans = sol.solve(a, b);
    for (int i = 0; i < n1; ++i) cout << ans[i] << (i + 1 == n1 ? "\n" : " ");
    return 0;
}
