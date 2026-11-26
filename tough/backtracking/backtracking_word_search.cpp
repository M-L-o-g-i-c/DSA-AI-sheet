// backtracking_word_search: DFS from each cell, marking visited cells
// topic: tough/backtracking — word search on a grid
// problem: LeetCode 79. Word Search
// links:
//   https://leetcode.com/problems/word-search/
//   https://leetcode.cn/problems/word-search/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Word Search
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/word-search/solution/

#include <bits/stdc++.h>
using namespace std;

// Try to extend the word from (r, c) at index k; restore the cell after exploring.
class Solution {
public:
    bool solve(vector<vector<char>>& board, string word) {
        int m = (int)board.size(), n = (int)board[0].size();
        function<bool(int, int, int)> dfs = [&](int r, int c, int k) -> bool {
            if (k == (int)word.size()) return true;
            if (r < 0 || r >= m || c < 0 || c >= n) return false;
            if (board[r][c] != word[k]) return false;
            char saved = board[r][c];
            board[r][c] = '#';   // choose: mark visited
            bool found = dfs(r + 1, c, k + 1) || dfs(r - 1, c, k + 1) ||
                         dfs(r, c + 1, k + 1) || dfs(r, c - 1, k + 1);   // explore
            board[r][c] = saved;   // unchoose
            return found;
        };
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(i, j, 0)) return true;
        return false;
    }
};

int main() {
    // input: m n \n m lines of n board chars each \n word
    int m, n;
    if (!(cin >> m >> n)) return 0;
    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    string word;
    cin >> word;
    Solution sol;
    cout << (sol.solve(board, word) ? 1 : 0) << "\n";
    return 0;
}
