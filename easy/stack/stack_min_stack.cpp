// stack_min_stack: LeetCode 155 — stack that reports its minimum in O(1)
// topic: easy/stack — min stack
// problem: LeetCode 155. Min Stack
// links:
//   https://leetcode.com/problems/min-stack/
//   https://leetcode.cn/problems/min-stack/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 155. Min Stack - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/min-stack/solution/

#include <bits/stdc++.h>
using namespace std;

// Second stack keeps the minimum of every prefix, so getMin is O(1).
class MinStack {
    stack<int> st, mins;

public:
    void push(int val) {
        st.push(val);
        if (mins.empty() || val <= mins.top()) mins.push(val);
    }
    void pop() {
        if (st.top() == mins.top()) mins.pop();
        st.pop();
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return mins.top();
    }
};

// Demo driver: runs the op script and reports values produced by each op.
class Solution {
public:
    vector<string> solve(const vector<string>& ops, const vector<int>& args) {
        MinStack st;
        vector<string> out;
        for (size_t i = 0; i < ops.size(); i++) {
            if (ops[i] == "push") st.push(args[i]);
            else if (ops[i] == "pop") {
                out.push_back(to_string(st.top()));  // report the removed value
                st.pop();
            } else if (ops[i] == "top") out.push_back(to_string(st.top()));
            else if (ops[i] == "getMin") out.push_back(to_string(st.getMin()));
        }
        return out;
    }
};

int main() {
    // input: n \n n lines: <op> [x]
    //   push x | pop | top | getMin  (script assumed valid: no pop/top/getMin on empty)
    // output: one line per pop/top/getMin op (pop prints the removed value)
    int n;
    if (!(cin >> n)) return 0;
    vector<string> ops(n);
    vector<int> args(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> ops[i];
        if (ops[i] == "push") cin >> args[i];
    }
    Solution sol;
    for (const string& line : sol.solve(ops, args)) cout << line << "\n";
    return 0;
}
