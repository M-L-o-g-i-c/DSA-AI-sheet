// string_reverse: LeetCode 344 — in-place reversal with two pointers
// topic: easy/strings — reverse string
// problem: LeetCode 344. Reverse String
// links:
//   https://leetcode.com/problems/reverse-string/
//   https://leetcode.cn/problems/reverse-string/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 344. Reverse String - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/reverse-string/solution/

#include <bits/stdc++.h>
using namespace std;

// Swap the two ends and walk inward — O(1) extra space.
class Solution {
public:
    void solve(vector<char>& s) {
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};

int main() {
    // input: one token — the string (e.g. hello)
    // output: the reversed string
    string t;
    if (!(cin >> t)) return 0;
    vector<char> s(t.begin(), t.end());
    Solution sol;
    sol.solve(s);
    cout << string(s.begin(), s.end()) << "\n";
    return 0;
}
