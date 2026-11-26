// grid_basic: grid input, 4-direction moves, BFS flood fill
// topic: medium/grids — grid basics (4-direction flood fill, BFS)
// problem: demo — recolor a 4-connected region with a direction-array flood fill
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

// 4-direction moves: the same (dr, dc) pair list works for BFS and DFS.
// Queue the start cell, then grow the region one ring of neighbors at a time.
class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>>& g, int sr, int sc, int color) {
        int r = (int)g.size(), c = (int)g[0].size();
        int start = g[sr][sc];
        if (start == color) return g;
        const int dr[4] = {1, -1, 0, 0};
        const int dc[4] = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        g[sr][sc] = color;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dr[d], ny = y + dc[d];
                if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                if (g[nx][ny] != start) continue;
                g[nx][ny] = color;
                q.push({nx, ny});
            }
        }
        return g;
    }
};

int main() {
    // input: r c sr sc color \n then r rows of c integers
    int r, c, sr, sc, color;
    if (!(cin >> r >> c >> sr >> sc >> color)) return 0;
    vector<vector<int>> g(r, vector<int>(c));
    for (auto& row : g)
        for (auto& v : row) cin >> v;
    Solution sol;
    vector<vector<int>> out = sol.solve(g, sr, sc, color);
    for (const auto& row : out) {
        for (size_t j = 0; j < row.size(); j++) {
            if (j) cout << ' ';
            cout << row[j];
        }
        cout << "\n";
    }
    return 0;
}
