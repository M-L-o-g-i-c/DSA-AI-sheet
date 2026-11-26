// string_hash_compare: O(1) substring equality via prefix hashes
// topic: tough/string-hashing — O(1) substring equality (prefix hashes)
// problem: LeetCode 187. Repeated DNA Sequences
// links:
//   https://leetcode.com/problems/repeated-dna-sequences/
//   https://leetcode.cn/problems/repeated-dna-sequences/
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: String Hashing
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/string/string-hashing.html

#include <bits/stdc++.h>
using namespace std;

// Prefix hashes: hash(s[l..r]) = pref[r+1] - pref[l] * B^(r-l+1) in O(1),
// so equal hashes stand in for equal substrings (probabilistically).
class Solution {
public:
    vector<string> solve(string s) {
        int n = (int)s.size();
        const int L = 10;
        vector<string> ans;
        if (n < L) return ans;

        // hash modulo 2^64 via unsigned overflow
        const unsigned long long B = 131;
        vector<unsigned long long> pw(n + 1), pref(n + 1);
        pw[0] = 1;
        for (int i = 0; i < n; i++) {
            pw[i + 1] = pw[i] * B;
            pref[i + 1] = pref[i] * B + (unsigned char)s[i];
        }
        auto substr_hash = [&](int l, int r) {
            return pref[r + 1] - pref[l] * pw[r - l + 1];
        };

        unordered_map<unsigned long long, int> seen;
        for (int i = 0; i + L - 1 < n; i++) {
            unsigned long long h = substr_hash(i, i + L - 1);
            if (++seen[h] == 2) ans.push_back(s.substr(i, L));
        }
        return ans;
    }
};

int main() {
    // input: string s (DNA: only A, C, G, T) — output repeated length-10 substrings, one per line
    string s;
    if (!(cin >> s)) return 0;
    Solution sol;
    for (const string& t : sol.solve(s)) cout << t << "\n";
    return 0;
}
