// number_theory_modpow: fast modular exponentiation (binary exponentiation)
// topic: unhinged/number-theory — fast modular exponentiation
// problem: demo — a^b mod m
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Binary Exponentiation
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/algebra/binary-exp.html

#include <bits/stdc++.h>
using namespace std;

// Scan the bits of b: square the base each step, multiply into the result
// when the bit is set. O(log b) multiplications instead of O(b).
class Solution {
public:
    long long solve(long long a, long long b, long long m) {
        long long res = 1;
        a %= m;
        while (b > 0) {
            if (b & 1) res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
};

int main() {
    // input: a b m (a >= 0, b >= 0, m >= 2) — output: a^b mod m
    long long a, b, m;
    if (!(cin >> a >> b >> m)) return 0;
    Solution sol;
    cout << sol.solve(a, b, m) << "\n";
    return 0;
}
