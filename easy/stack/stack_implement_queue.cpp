// stack_implement_queue: LeetCode 232 — FIFO queue built from two stacks
// topic: easy/stack — implement queue using stacks
// problem: LeetCode 232. Implement Queue using Stacks
// links:
//   https://leetcode.com/problems/implement-queue-using-stacks/
//   https://leetcode.cn/problems/implement-queue-using-stacks/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 232. Implement Queue using Stacks - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/implement-queue-using-stacks/solution/

#include <bits/stdc++.h>
using namespace std;

// Push to inSt; on pop/peek, pour inSt into outSt once — amortized O(1).
class MyQueue {
    stack<int> inSt, outSt;

    void pour() {
        while (!inSt.empty()) {
            outSt.push(inSt.top());
            inSt.pop();
        }
    }

public:
    void push(int x) {
        inSt.push(x);
    }
    int pop() {
        if (outSt.empty()) pour();
        int v = outSt.top();
        outSt.pop();
        return v;
    }
    int peek() {
        if (outSt.empty()) pour();
        return outSt.top();
    }
    bool empty() {
        return inSt.empty() && outSt.empty();
    }
};

// Demo driver: runs the op script on MyQueue and reports each op's result.
class Solution {
public:
    vector<string> solve(const vector<string>& ops, const vector<int>& args) {
        MyQueue q;
        vector<string> out;
        for (size_t i = 0; i < ops.size(); i++) {
            if (ops[i] == "push") q.push(args[i]);
            else if (ops[i] == "pop") out.push_back(to_string(q.pop()));
            else if (ops[i] == "peek") out.push_back(to_string(q.peek()));
            else if (ops[i] == "empty") out.push_back(q.empty() ? "true" : "false");
        }
        return out;
    }
};

int main() {
    // input: n \n n lines: <op> [x]
    //   push x | pop | peek | empty  (script assumed valid: no pop/peek on empty)
    // output: one line per pop/peek/empty op
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
