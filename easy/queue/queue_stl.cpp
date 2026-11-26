// queue_stl: std::queue and std::deque usage
// topic: easy/queue — STL usage (std::queue, std::deque)
// problem: demo — FIFO ops on std::queue and two-ended ops on std::deque
// links:   (demo, no external problem)
// reference:
//   Author(s): cppreference contributors
//   Date: 2026-11-26 (accessed)
//   Title: std::queue
//   Code version: online article
//   Type: article
//   URL: https://en.cppreference.com/w/cpp/container/queue.html

#include <bits/stdc++.h>
using namespace std;

// std::queue: push / pop / front / empty (FIFO adaptor).
// std::deque: push_back / push_front / pop_front / pop_back / back (both ends).
class Solution {
public:
    vector<string> solve(const vector<string>& ops, const vector<int>& args) {
        queue<int> q;
        deque<int> dq;
        vector<string> out;
        for (size_t i = 0; i < ops.size(); i++) {
            const string& op = ops[i];
            if (op == "push") q.push(args[i]);
            else if (op == "pop") {
                out.push_back(to_string(q.front()));  // report the removed value
                q.pop();
            } else if (op == "front") out.push_back(to_string(q.front()));
            else if (op == "empty") out.push_back(q.empty() ? "true" : "false");
            else if (op == "push_back") dq.push_back(args[i]);
            else if (op == "push_front") dq.push_front(args[i]);
            else if (op == "pop_front") {
                out.push_back(to_string(dq.front()));
                dq.pop_front();
            } else if (op == "pop_back") {
                out.push_back(to_string(dq.back()));
                dq.pop_back();
            } else if (op == "back") out.push_back(to_string(dq.back()));
        }
        return out;
    }
};

int main() {
    // input: n \n n lines: <op> [x]
    //   queue ops: push x | pop | front | empty
    //   deque ops: push_back x | push_front x | pop_front | pop_back | back
    // output: one line per op that produces a value
    int n;
    if (!(cin >> n)) return 0;
    vector<string> ops(n);
    vector<int> args(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> ops[i];
        if (ops[i] == "push" || ops[i] == "push_back" || ops[i] == "push_front")
            cin >> args[i];
    }
    Solution sol;
    for (const string& line : sol.solve(ops, args)) cout << line << "\n";
    return 0;
}
