// sliding_window_min_window: smallest substring covering all characters of t
// topic: medium/sliding-window — variable window with need/have counts
// problem: LeetCode 76. Minimum Window Substring
// links:
//   https://leetcode.com/problems/minimum-window-substring/
//   https://leetcode.cn/problems/minimum-window-substring/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Minimum Window Substring
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/minimum-window-substring/solution/

#include <bits/stdc++.h>
using namespace std;

// need[c] is the remaining demand (negative = surplus); missing counts unsatisfied chars.
class Solution {
public:
    string solve(string s, string t) {
        vector<int> need(128, 0);
        for (char c : t) need[c]++;
        int missing = (int)t.size();
        int bestLen = INT_MAX, bestL = 0, lo = 0;
        for (int hi = 0; hi < (int)s.size(); ++hi) {
            if (need[s[hi]] > 0) missing--;
            need[s[hi]]--;
            while (missing == 0) {
                if (hi - lo + 1 < bestLen) {
                    bestLen = hi - lo + 1;
                    bestL = lo;
                }
                need[s[lo]]++;
                if (need[s[lo]] > 0) missing++;
                ++lo;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
    }
};

int main() {
    // input: s t   (two words, English letters)
    string s, t;
    if (!(cin >> s >> t)) return 0;
    Solution sol;
    cout << sol.solve(s, t) << "\n";
    return 0;
}
