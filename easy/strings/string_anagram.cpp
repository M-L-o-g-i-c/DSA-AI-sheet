// string_anagram: LeetCode 242 — anagram check by letter counts
// topic: easy/strings — valid anagram
// problem: LeetCode 242. Valid Anagram
// links:
//   https://leetcode.com/problems/valid-anagram/
//   https://leetcode.cn/problems/valid-anagram/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 242. Valid Anagram - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/valid-anagram/solution/

#include <bits/stdc++.h>
using namespace std;

// Count each letter of s up and of t down; anagrams cancel to all zeros.
class Solution {
public:
    bool solve(string s, string t) {
        if (s.size() != t.size()) return false;
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;
        for (char c : t) cnt[c - 'a']--;
        for (int x : cnt)
            if (x != 0) return false;
        return true;
    }
};

int main() {
    // input: two tokens s t (lowercase English letters)
    string s, t;
    if (!(cin >> s >> t)) return 0;
    Solution sol;
    cout << (sol.solve(s, t) ? "true" : "false") << "\n";
    return 0;
}
