// stack_stl: std::stack usage
// topic: easy/stack — STL usage (std::stack)
// problem: demo — std::stack push, pop, top, empty
// links:   (demo, no external problem)
// reference:
//   Author(s): cppreference contributors
//   Date: 2026-11-26 (accessed)
//   Title: std::stack
//   Code version: online article
//   Type: article
//   URL: https://en.cppreference.com/w/cpp/container/stack.html

#include <bits/stdc++.h>
using namespace std;

// std::stack adaptor: push / pop / top / empty (LIFO over any sequence container).
class Solution {
public:
    vector<string> solve(const vector<string>& ops, const vector<int>& args) {
        stack<int> st;
        vector<string> out;
        for (size_t i = 0; i < ops.size(); i++) {
            if (ops[i] == "push") st.push(args[i]);
            else if (ops[i] == "pop") {
                out.push_back(to_string(st.top()));  // report the removed value
                st.pop();
            } else if (ops[i] == "top") out.push_back(to_string(st.top()));
            else if (ops[i] == "empty") out.push_back(st.empty() ? "true" : "false");
        }
        return out;
    }
};

int main() {
    // input: n \n n lines: <op> [x]
    //   push x | pop | top | empty   (script assumed valid: no pop/top on empty)
    // output: one line per pop/top/empty op (pop prints the removed value)
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
