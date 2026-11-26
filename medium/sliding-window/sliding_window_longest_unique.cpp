// sliding_window_longest_unique: longest substring with all unique characters
// topic: medium/sliding-window — variable window with last-seen index
// problem: LeetCode 3. Longest Substring Without Repeating Characters
// links:
//   https://leetcode.com/problems/longest-substring-without-repeating-characters/
//   https://leetcode.cn/problems/longest-substring-without-repeating-characters/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Longest Substring Without Repeating Characters
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/solution/

#include <bits/stdc++.h>
using namespace std;

// Keep [lo..hi] duplicate-free: on a repeat, jump lo past the previous occurrence.
class Solution {
public:
    int solve(string s) {
        unordered_map<char, int> last;
        int lo = 0, best = 0;
        for (int hi = 0; hi < (int)s.size(); ++hi) {
            char c = s[hi];
            if (last.count(c)) lo = max(lo, last[c] + 1);
            last[c] = hi;
            best = max(best, hi - lo + 1);
        }
        return best;
    }
};

int main() {
    // input: s   (one line, may contain spaces)
    string s;
    if (!getline(cin, s)) return 0;
    Solution sol;
    cout << sol.solve(s) << "\n";
    return 0;
}
