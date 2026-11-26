// stack_basic: hand-rolled stack over a fixed array (push, pop, top)
// topic: easy/stack — how it works (array stack)
// problem: demo — fixed-capacity array stack: push, pop, top
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

// Fixed-capacity LIFO stack: the element count is the stack pointer.
class ArrayStack {
    static const int CAP = 1000;
    int data[CAP];
    int cnt = 0;

public:
    void push(int x) {
        data[cnt++] = x;
    }
    void pop() {
        cnt--;
    }
    int top() const {
        return data[cnt - 1];
    }
    bool empty() const {
        return cnt == 0;
    }
};

// Demo driver: runs the op script and reports values produced by each op.
class Solution {
public:
    vector<string> solve(const vector<string>& ops, const vector<int>& args) {
        ArrayStack st;
        vector<string> out;
        for (size_t i = 0; i < ops.size(); i++) {
            if (ops[i] == "push") st.push(args[i]);
            else if (ops[i] == "pop") {
                out.push_back(to_string(st.top()));  // report the removed value
                st.pop();
            } else if (ops[i] == "top") out.push_back(to_string(st.top()));
        }
        return out;
    }
};

int main() {
    // input: n \n n lines: <op> [x]
    //   push x | pop | top           (script assumed valid: no pop/top on empty)
    // output: one line per pop/top op (pop prints the removed value)
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
