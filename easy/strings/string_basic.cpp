// string_basic: std::string iterate/index basics
// topic: easy/strings — how it works (iterate/index basics)
// problem: demo — iterate a std::string and index its characters
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

// Count vowels by walking with an index and reading characters via s[i].
// Range-for is the shorthand for the same traversal: for (char c : s).
class Solution {
public:
    int solve(const string& s) {
        int cnt = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
        }
        return cnt;
    }
};

int main() {
    // input: one token — the string (e.g. application)
    // output: number of vowels
    string s;
    if (!(cin >> s)) return 0;
    Solution sol;
    cout << sol.solve(s) << "\n";
    return 0;
}
