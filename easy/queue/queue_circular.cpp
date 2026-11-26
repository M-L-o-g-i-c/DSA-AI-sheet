// queue_circular: LeetCode 622 — fixed-size circular queue
// topic: easy/queue — design circular queue
// problem: LeetCode 622. Design Circular Queue
// links:
//   https://leetcode.com/problems/design-circular-queue/
//   https://leetcode.cn/problems/design-circular-queue/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 622. Design Circular Queue - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/design-circular-queue/solution/

#include <bits/stdc++.h>
using namespace std;

// Ring buffer: head index + count; slots wrap modulo k.
class MyCircularQueue {
    vector<int> data;
    int head = 0;
    int cnt = 0;

public:
    MyCircularQueue(int k) : data(k) {}
    bool enQueue(int value) {
        if (isFull()) return false;
        data[(head + cnt) % (int)data.size()] = value;
        cnt++;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % (int)data.size();
        cnt--;
        return true;
    }
    int Front() const {
        return isEmpty() ? -1 : data[head];
    }
    int Rear() const {
        return isEmpty() ? -1 : data[(head + cnt - 1) % (int)data.size()];
    }
    bool isEmpty() const {
        return cnt == 0;
    }
    bool isFull() const {
        return cnt == (int)data.size();
    }
};

// Demo driver: runs the op script and reports each op's return value.
class Solution {
public:
    vector<string> solve(int k, const vector<string>& ops, const vector<int>& args) {
        MyCircularQueue q(k);
        vector<string> out;
        for (size_t i = 0; i < ops.size(); i++) {
            const string& op = ops[i];
            if (op == "enQueue") out.push_back(q.enQueue(args[i]) ? "true" : "false");
            else if (op == "deQueue") out.push_back(q.deQueue() ? "true" : "false");
            else if (op == "Front") out.push_back(to_string(q.Front()));
            else if (op == "Rear") out.push_back(to_string(q.Rear()));
            else if (op == "isEmpty") out.push_back(q.isEmpty() ? "true" : "false");
            else if (op == "isFull") out.push_back(q.isFull() ? "true" : "false");
        }
        return out;
    }
};

int main() {
    // input: k n \n n lines: <op> [x]
    //   enQueue x | deQueue | Front | Rear | isEmpty | isFull
    // output: one line per op (its return value)
    int k, n;
    if (!(cin >> k >> n)) return 0;
    vector<string> ops(n);
    vector<int> args(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> ops[i];
        if (ops[i] == "enQueue") cin >> args[i];
    }
    Solution sol;
    for (const string& line : sol.solve(k, ops, args)) cout << line << "\n";
    return 0;
}
