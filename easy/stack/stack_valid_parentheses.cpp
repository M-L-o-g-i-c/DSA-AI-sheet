// stack_valid_parentheses: LeetCode 20 — bracket matching with a stack
// topic: easy/stack — valid parentheses
// problem: LeetCode 20. Valid Parentheses
// links:
//   https://leetcode.com/problems/valid-parentheses/
//   https://leetcode.cn/problems/valid-parentheses/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 20. Valid Parentheses - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/valid-parentheses/solution/

#include <bits/stdc++.h>
using namespace std;

// Push openings; each closing must match the most recent unmatched opening.
class Solution {
public:
    bool solve(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char open = st.top();
                st.pop();
                if ((c == ')' && open != '(') ||
                    (c == ']' && open != '[') ||
                    (c == '}' && open != '{'))
                    return false;
            }
        }
        return st.empty();
    }
};

int main() {
    // input: one token — the bracket string (e.g. ([]))
    string s;
    if (!(cin >> s)) return 0;
    Solution sol;
    cout << (sol.solve(s) ? "true" : "false") << "\n";
    return 0;
}
