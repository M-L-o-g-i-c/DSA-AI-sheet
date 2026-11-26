// queue_basic: hand-rolled circular queue over a fixed array (push, pop, front)
// topic: easy/queue — how it works (array/circular queue)
// problem: demo — fixed-capacity circular queue: enqueue, dequeue, front
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

// Fixed-capacity FIFO queue: head index + element count, slots wrap modulo CAP.
class ArrayQueue {
    static const int CAP = 1000;
    int data[CAP];
    int head = 0;  // index of the front element
    int cnt = 0;   // number of elements currently stored

public:
    void push(int x) {
        data[(head + cnt) % CAP] = x;
        cnt++;
    }
    void pop() {
        head = (head + 1) % CAP;
        cnt--;
    }
    int front() const {
        return data[head];
    }
    bool empty() const {
        return cnt == 0;
    }
};

// Demo driver: runs the op script and reports values produced by each op.
class Solution {
public:
    vector<string> solve(const vector<string>& ops, const vector<int>& args) {
        ArrayQueue q;
        vector<string> out;
        for (size_t i = 0; i < ops.size(); i++) {
            if (ops[i] == "push") q.push(args[i]);
            else if (ops[i] == "pop") {
                out.push_back(to_string(q.front()));  // report the removed value
                q.pop();
            } else if (ops[i] == "front") out.push_back(to_string(q.front()));
        }
        return out;
    }
};

int main() {
    // input: n \n n lines: <op> [x]
    //   push x | pop | front        (script assumed valid: no pop/front on empty)
    // output: one line per pop/front op (pop prints the removed value)
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
