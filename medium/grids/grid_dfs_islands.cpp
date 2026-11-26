// grid_dfs_islands: DFS island counting
// topic: medium/grids — number of islands (DFS)
// problem: LeetCode 200. Number of Islands
// links:   https://leetcode.com/problems/number-of-islands/
//          https://leetcode.cn/problems/number-of-islands/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Number of Islands - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/number-of-islands/solution/

#include <bits/stdc++.h>
using namespace std;

// Each unvisited '1' starts a new island; DFS sinks the whole component.
class Solution {
public:
    int solve(vector<vector<char>>& grid) {
        int r = (int)grid.size();
        if (r == 0) return 0;
        int c = (int)grid[0].size();
        int islands = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (grid[i][j] == '1') {
                    islands++;
                    sink(grid, i, j);
                }
        return islands;
    }

private:
    void sink(vector<vector<char>>& g, int i, int j) {
        if (i < 0 || j < 0 || i >= (int)g.size() || j >= (int)g[0].size()) return;
        if (g[i][j] != '1') return;
        g[i][j] = '0';
        sink(g, i + 1, j);
        sink(g, i - 1, j);
        sink(g, i, j + 1);
        sink(g, i, j - 1);
    }
};

int main() {
    // input: r c \n then r rows of c characters '0'/'1' (no spaces)
    int r, c;
    if (!(cin >> r >> c)) return 0;
    vector<vector<char>> g(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < c; j++) g[i][j] = row[j];
    }
    Solution sol;
    cout << sol.solve(g) << "\n";
    return 0;
}
