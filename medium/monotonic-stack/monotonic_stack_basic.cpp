// monotonic_stack_basic: next greater and previous smaller with stacks
// topic: medium/monotonic-stack — increasing and decreasing stack
// problem: demo — next greater element and previous smaller element for every index
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

// Decreasing stack (top = smallest pending) answers next greater;
// increasing stack (top = largest pending) answers previous smaller.
class Solution {
public:
    pair<vector<int>, vector<int>> solve(const vector<int>& a) {
        int n = (int)a.size();
        vector<int> nextGreater(n, -1), prevSmaller(n, -1);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && a[st.top()] < a[i]) {
                nextGreater[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && a[st.top()] > a[i]) st.pop();
            prevSmaller[i] = st.empty() ? -1 : a[st.top()];
            st.push(i);
        }
        return {nextGreater, prevSmaller};
    }
};

int main() {
    // input: n \n a[0] ... a[n-1]
    // output: next greater values, then previous smaller values (-1 if none)
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    auto [ng, ps] = sol.solve(a);
    for (int i = 0; i < n; ++i) cout << ng[i] << (i + 1 == n ? "\n" : " ");
    for (int i = 0; i < n; ++i) cout << ps[i] << (i + 1 == n ? "\n" : " ");
    return 0;
}
