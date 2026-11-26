// grid_bfs_rotting: BFS multi-source rotting oranges
// topic: medium/grids — rotting oranges (multi-source BFS)
// problem: LeetCode 994. Rotting Oranges
// links:   https://leetcode.com/problems/rotting-oranges/
//          https://leetcode.cn/problems/rotting-oranges/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Rotting Oranges - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/rotting-oranges/solution/

#include <bits/stdc++.h>
using namespace std;

// All rotten oranges start BFS together; one BFS ring is one minute.
class Solution {
public:
    int solve(vector<vector<int>>& grid) {
        int r = (int)grid.size(), c = (int)grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        const int dr[4] = {1, -1, 0, 0};
        const int dc[4] = {0, 0, 1, -1};
        int minutes = 0;
        while (!q.empty() && fresh > 0) {
            int sz = (int)q.size();
            for (int k = 0; k < sz; k++) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dr[d], ny = y + dc[d];
                    if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                    if (grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};

int main() {
    // input: r c \n then r rows of c integers (0 empty, 1 fresh, 2 rotten)
    int r, c;
    if (!(cin >> r >> c)) return 0;
    vector<vector<int>> g(r, vector<int>(c));
    for (auto& row : g)
        for (auto& v : row) cin >> v;
    Solution sol;
    cout << sol.solve(g) << "\n";
    return 0;
}
