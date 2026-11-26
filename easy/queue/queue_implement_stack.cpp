// queue_implement_stack: LeetCode 225 — LIFO stack built from a queue
// topic: easy/queue — implement stack using queues
// problem: LeetCode 225. Implement Stack using Queues
// links:
//   https://leetcode.com/problems/implement-stack-using-queues/
//   https://leetcode.cn/problems/implement-stack-using-queues/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 225. Implement Stack using Queues - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/implement-stack-using-queues/solution/

#include <bits/stdc++.h>
using namespace std;

// One queue: push rotates the queue so the newest element sits at the front.
class MyStack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        for (int i = 0, n = (int)q.size() - 1; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int v = q.front();
        q.pop();
        return v;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};

// Demo driver: runs the op script on MyStack and reports each op's result.
class Solution {
public:
    vector<string> solve(const vector<string>& ops, const vector<int>& args) {
        MyStack st;
        vector<string> out;
        for (size_t i = 0; i < ops.size(); i++) {
            if (ops[i] == "push") st.push(args[i]);
            else if (ops[i] == "pop") out.push_back(to_string(st.pop()));
            else if (ops[i] == "top") out.push_back(to_string(st.top()));
            else if (ops[i] == "empty") out.push_back(st.empty() ? "true" : "false");
        }
        return out;
    }
};

int main() {
    // input: n \n n lines: <op> [x]
    //   push x | pop | top | empty   (script assumed valid: no pop/top on empty)
    // output: one line per pop/top/empty op
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
