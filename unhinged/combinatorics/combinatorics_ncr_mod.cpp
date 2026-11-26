// combinatorics_ncr_mod: nCr mod p via factorials + modular inverse
// topic: unhinged/combinatorics — nCr mod p (factorials + modular inverse)
// problem: demo — compute C(n, r) modulo 1e9+7
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Binomial Coefficients
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/combinatorics/binomial-coefficients.html

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1'000'000'007;
const int MAXN = 1'000'000;

// C(n,r) mod p = fact[n] * invFact[r] * invFact[n-r] mod p
class Solution {
    vector<long long> fact, invFact;

    long long modPow(long long a, long long e) {
        long long r = 1;
        while (e) {
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }

public:
    Solution() : fact(MAXN + 1), invFact(MAXN + 1) {
        fact[0] = 1;
        for (int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
        // invFact[n] = fact[n]^(p-2) mod p (Fermat), then walk downwards
        invFact[MAXN] = modPow(fact[MAXN], MOD - 2);
        for (int i = MAXN; i >= 1; i--) invFact[i - 1] = invFact[i] * i % MOD;
    }

    long long solve(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }
};

int main() {
    // input: n r   (0 <= r <= n <= 1e6)
    int n, r;
    if (!(cin >> n >> r)) return 0;
    Solution sol;
    cout << sol.solve(n, r) << "\n";
    return 0;
}
