// backtracking_combinations: choose k of 1..n by exploring increasing starts
// topic: tough/backtracking — combination generation
// problem: LeetCode 77. Combinations
// links:
//   https://leetcode.com/problems/combinations/
//   https://leetcode.cn/problems/combinations/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Combinations
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/combinations/solution/

#include <bits/stdc++.h>
using namespace std;

// Only pick numbers >= start so each combination is generated once, in order.
class Solution {
public:
    vector<vector<int>> solve(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int)> dfs = [&](int start) {
            if ((int)cur.size() == k) {
                res.push_back(cur);
                return;
            }
            for (int i = start; i <= n; i++) {
                cur.push_back(i);   // choose
                dfs(i + 1);         // explore
                cur.pop_back();     // unchoose
            }
        };
        dfs(1);
        return res;
    }
};

int main() {
    // input: n k
    int n, k;
    if (!(cin >> n >> k)) return 0;
    Solution sol;
    vector<vector<int>> res = sol.solve(n, k);
    for (const auto& comb : res) {
        for (size_t i = 0; i < comb.size(); i++) {
            if (i) cout << " ";
            cout << comb[i];
        }
        cout << "\n";
    }
    return 0;
}
