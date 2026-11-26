// number_theory_mod_inverse: modular inverse via Fermat and extended Euclid
// topic: unhinged/number-theory — modular inverse (Fermat / extended Euclid)
// problem: demo — inverse of a modulo m by two methods
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Modular Inverse
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/algebra/module-inverse.html

#include <bits/stdc++.h>
using namespace std;

// Both methods need gcd(a, m) = 1; Fermat additionally needs m prime.
// Fermat: a^(m-2) mod m. Extended Euclid: x in a*x + m*y = 1, taken mod m.
class Solution {
    long long modpow(long long a, long long b, long long m) {
        long long res = 1;
        a %= m;
        while (b > 0) {
            if (b & 1) res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }

    // returns {x, y} with a*x + b*y = gcd(a, b)
    pair<long long, long long> ext_gcd(long long a, long long b) {
        if (b == 0) return {1, 0};
        auto [x1, y1] = ext_gcd(b, a % b);
        return {y1, x1 - a / b * y1};
    }

public:
    // returns {inverse by Fermat, inverse by extended Euclid}
    pair<long long, long long> solve(long long a, long long m) {
        long long inv_fermat = modpow(a, m - 2, m);
        long long x = ext_gcd(a, m).first;
        long long inv_ext = (x % m + m) % m;
        return {inv_fermat, inv_ext};
    }
};

int main() {
    // input: a m (m prime, gcd(a,m)=1) — output: "inv_fermat inv_ext"
    long long a, m;
    if (!(cin >> a >> m)) return 0;
    Solution sol;
    auto [inv1, inv2] = sol.solve(a, m);
    cout << inv1 << " " << inv2 << "\n";
    return 0;
}
