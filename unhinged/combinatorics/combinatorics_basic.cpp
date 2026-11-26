// combinatorics_basic: factorial + binomial coefficient nCr
// topic: unhinged/combinatorics — factorial + nCr
// problem: demo — compute C(n, r) from factorials
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

// nCr built from factorials: C(n,r) = n! / (r! * (n-r)!)
class Solution {
public:
    long long fact(int n) {
        long long f = 1;
        for (int i = 2; i <= n; i++) f *= i;
        return f;
    }

    long long solve(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact(n) / (fact(r) * fact(n - r));
    }
};

int main() {
    // input: n r   (0 <= r <= n <= 20 so that n! fits in 64 bits)
    int n, r;
    if (!(cin >> n >> r)) return 0;
    Solution sol;
    cout << sol.solve(n, r) << "\n";
    return 0;
}
