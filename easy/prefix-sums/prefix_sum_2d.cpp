// prefix_sum_2d: 2D prefix sums for O(1) rectangle range sums
// topic: easy/prefix-sums — 2D prefix sums
// problem: LeetCode 304. Range Sum Query 2D - Immutable
// links:   https://leetcode.com/problems/range-sum-query-2d-immutable/
//          https://leetcode.cn/problems/range-sum-query-2d-immutable/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 304. Range Sum Query 2D - Immutable - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/range-sum-query-2d-immutable/solution/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // pref[i+1][j+1] = sum of matrix[0..i][0..j]; region sum by inclusion-exclusion.
    int solve(vector<vector<int>>& matrix, int row1, int col1, int row2, int col2) {
        int r = (int)matrix.size(), c = (int)matrix[0].size();
        vector<vector<int>> pref(r + 1, vector<int>(c + 1, 0));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                pref[i + 1][j + 1] = matrix[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
        return pref[row2 + 1][col2 + 1] - pref[row1][col2 + 1] - pref[row2 + 1][col1] + pref[row1][col1];
    }
};

int main() {
    // input: r c \n matrix (r rows of c ints) \n q \n then q lines of row1 col1 row2 col2
    int r, c;
    if (!(cin >> r >> c)) return 0;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (auto& row : matrix)
        for (auto& v : row) cin >> v;
    int q;
    cin >> q;
    Solution sol;
    // output: one region sum per line
    while (q--) {
        int row1, col1, row2, col2;
        cin >> row1 >> col1 >> row2 >> col2;
        cout << sol.solve(matrix, row1, col1, row2, col2) << "\n";
    }
    return 0;
}
