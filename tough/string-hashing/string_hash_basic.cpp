// string_hash_basic: polynomial rolling hash of a string or substring
// topic: tough/string-hashing — how it works (polynomial rolling hash)
// problem: demo — hash of substring s[l..r] by direct polynomial evaluation
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: String Hashing
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/string/string-hashing.html

#include <bits/stdc++.h>
using namespace std;

// h(s[l..r]) = sum s[i] * B^(r-i) mod M, built left to right.
// Hash of the whole string is just the query l = 0, r = n - 1.
class Solution {
public:
    long long solve(const string& s, int l, int r) {
        const long long B = 131, M = 1e9 + 7;
        long long h = 0;
        for (int i = l; i <= r; i++) {
            h = (h * B + (s[i] - 'a' + 1)) % M;
        }
        return h;
    }
};

int main() {
    // input: string s (lowercase) \n q \n q lines "l r" (0-based, inclusive substring bounds)
    string s;
    if (!(cin >> s)) return 0;
    int q;
    cin >> q;
    Solution sol;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << sol.solve(s, l, r) << "\n";
    }
    return 0;
}
