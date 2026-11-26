// grid_flood_fill: DFS flood fill
// topic: medium/grids — flood fill (DFS)
// problem: LeetCode 733. Flood Fill
// links:   https://leetcode.com/problems/flood-fill/
//          https://leetcode.cn/problems/flood-fill/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Flood Fill - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/flood-fill/solution/

#include <bits/stdc++.h>
using namespace std;

// Recolor the 4-connected region holding (sr, sc); skip if already colored.
class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc];
        if (start != color) dfs(image, sr, sc, start, color);
        return image;
    }

private:
    void dfs(vector<vector<int>>& img, int i, int j, int start, int color) {
        if (i < 0 || j < 0 || i >= (int)img.size() || j >= (int)img[0].size()) return;
        if (img[i][j] != start) return;
        img[i][j] = color;
        dfs(img, i + 1, j, start, color);
        dfs(img, i - 1, j, start, color);
        dfs(img, i, j + 1, start, color);
        dfs(img, i, j - 1, start, color);
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
