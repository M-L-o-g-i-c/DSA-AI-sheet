// string_hash_rabin_karp: Rabin-Karp pattern search
// topic: tough/string-hashing — Rabin-Karp pattern search
// problem: LeetCode 28. Find the Index of the First Occurrence in a String
// links:
//   https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
//   https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Rabin-Karp Algorithm for string matching
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/string/rabin-karp.html

#include <bits/stdc++.h>
using namespace std;

// Roll a hash over every window of length |needle|; verify hash hits with a
// direct compare so collisions cannot produce a wrong answer.
class Solution {
public:
    int solve(string haystack, string needle) {
        int n = (int)haystack.size(), m = (int)needle.size();
        if (m == 0) return 0;
        if (m > n) return -1;

        // hash modulo 2^64 via unsigned overflow
        const unsigned long long B = 131;
        unsigned long long nh = 0, hh = 0, power = 1;
        for (int i = 0; i < m; i++) {
            nh = nh * B + (unsigned char)needle[i];
            hh = hh * B + (unsigned char)haystack[i];
            if (i > 0) power *= B;
        }
        for (int i = 0; i + m <= n; i++) {
            if (hh == nh && haystack.compare(i, m, needle) == 0) return i;
            if (i + m < n) {
                hh = (hh - (unsigned char)haystack[i] * power) * B
                     + (unsigned char)haystack[i + m];
            }
        }
        return -1;
    }
};

int main() {
    // input: haystack \n needle (two strings) — output first occurrence index or -1
    string haystack, needle;
    if (!(cin >> haystack >> needle)) return 0;
    Solution sol;
    cout << sol.solve(haystack, needle) << "\n";
    return 0;
}
