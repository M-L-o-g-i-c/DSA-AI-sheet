// backtracking_n_queens: place queens row by row with column/diagonal guards
// topic: tough/backtracking — N-Queens
// problem: LeetCode 51. N-Queens
// links:
//   https://leetcode.com/problems/n-queens/
//   https://leetcode.cn/problems/n-queens/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: N-Queens
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/n-queens/solution/

#include <bits/stdc++.h>
using namespace std;

// Place one queen per row; col/diag1/diag2 mark attacked columns and diagonals.
class Solution {
public:
    vector<vector<string>> solve(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> col(n, 0), diag1(2 * n, 0), diag2(2 * n, 0);
        function<void(int)> dfs = [&](int row) {
            if (row == n) {
                res.push_back(board);
                return;
            }
            for (int c = 0; c < n; c++) {
                if (col[c] || diag1[row - c + n] || diag2[row + c]) continue;
                col[c] = diag1[row - c + n] = diag2[row + c] = 1;   // choose
                board[row][c] = 'Q';
                dfs(row + 1);                                       // explore
                board[row][c] = '.';                                // unchoose
                col[c] = diag1[row - c + n] = diag2[row + c] = 0;
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
    vector<vector<string>> res = sol.solve(n);
    for (const auto& placement : res) {
        for (const string& row : placement) cout << row << "\n";
        cout << "\n";
    }
    return 0;
}
