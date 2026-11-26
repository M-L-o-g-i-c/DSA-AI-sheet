// dp_edit_distance: min insert/delete/replace ops turning word1 into word2
// topic: tough/dynamic-programming — edit distance (Levenshtein)
// problem: LeetCode 72. Edit Distance
// links:
//   https://leetcode.com/problems/edit-distance/
//   https://leetcode.cn/problems/edit-distance/
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Edit Distance
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/string/edit_distance.html

#include <bits/stdc++.h>
using namespace std;

// dp[i][j] = min edits turning word1[0..i) into word2[0..j).
// Match costs nothing; otherwise min of insert, delete, replace.
class Solution {
public:
    int solve(string word1, string word2) {
        int m = (int)word1.size(), n = (int)word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = 1 + min({dp[i - 1][j],        // delete
                                        dp[i][j - 1],        // insert
                                        dp[i - 1][j - 1]});  // replace
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    // input: word1 word2   (two strings)
    string word1, word2;
    if (!(cin >> word1 >> word2)) return 0;
    Solution sol;
    cout << sol.solve(word1, word2) << "\n";
    return 0;
}
