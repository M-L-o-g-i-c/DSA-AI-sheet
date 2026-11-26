// number_theory_factorization: prime factorization by trial division
// topic: unhinged/number-theory — trial division factorization
// problem: demo — prime factorization of n
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Integer factorization
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/algebra/factorization.html

#include <bits/stdc++.h>
using namespace std;

// Try every divisor d up to sqrt(n) and divide it out completely; whatever
// remains above 1 at the end is itself prime.
class Solution {
public:
    // returns (prime, exponent) pairs in increasing order
    vector<pair<long long, int>> solve(long long n) {
        vector<pair<long long, int>> fac;
        for (long long d = 2; d * d <= n; d++) {
            if (n % d != 0) continue;
            int e = 0;
            while (n % d == 0) {
                n /= d;
                e++;
            }
            fac.push_back({d, e});
        }
        if (n > 1) fac.push_back({n, 1});
        return fac;
    }
};

int main() {
    // input: n (n >= 1) — output: "p1^e1 p2^e2 ...", e.g. 360 -> 2^3 3^2 5^1
    long long n;
    if (!(cin >> n)) return 0;
    Solution sol;
    auto fac = sol.solve(n);
    for (int i = 0; i < (int)fac.size(); i++) {
        if (i) cout << " ";
        cout << fac[i].first << "^" << fac[i].second;
    }
    cout << "\n";
    return 0;
}
