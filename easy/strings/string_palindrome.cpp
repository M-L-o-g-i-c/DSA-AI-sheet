// string_palindrome: LeetCode 125 — palindrome check skipping non-alphanumerics
// topic: easy/strings — valid palindrome
// problem: LeetCode 125. Valid Palindrome
// links:
//   https://leetcode.com/problems/valid-palindrome/
//   https://leetcode.cn/problems/valid-palindrome/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 125. Valid Palindrome - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/valid-palindrome/solution/

#include <bits/stdc++.h>
using namespace std;

// Two pointers inward, skipping anything that is not a letter or digit.
class Solution {
public:
    bool solve(string s) {
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum((unsigned char)s[i])) i++;
            while (i < j && !isalnum((unsigned char)s[j])) j--;
            if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    // input: one line — the candidate string (may contain spaces and punctuation)
    string s;
    if (!getline(cin, s)) return 0;
    Solution sol;
    cout << (sol.solve(s) ? "true" : "false") << "\n";
    return 0;
}
