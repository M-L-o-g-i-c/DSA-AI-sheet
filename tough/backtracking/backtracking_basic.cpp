// backtracking_basic: choose/explore/unchoose template
// topic: tough/backtracking — choose/explore/unchoose template
// problem: demo — generate all binary strings of length n
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

// Backtracking template: choose a candidate, explore, then unchoose to
// restore state before trying the next candidate.
class Solution {
public:
    vector<string> solve(int n) {
        vector<string> res;
        string cur;
        function<void(int)> dfs = [&](int pos) {
            if (pos == n) {
                res.push_back(cur);
                return;
            }
            for (char c : {'0', '1'}) {
                cur.push_back(c);   // choose
                dfs(pos + 1);       // explore
                cur.pop_back();     // unchoose
            }
        };
        dfs(0);
        return res;
    }
};

int main() {
    // input: n
    int n;
    if (!(cin >> n)) return 0;
    Solution sol;
    vector<string> res = sol.solve(n);
    for (const string& s : res) cout << s << "\n";
    return 0;
}
