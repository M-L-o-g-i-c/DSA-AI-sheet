// combinatorics_catalan: Catalan numbers via C(2n,n)/(n+1)
// topic: unhinged/combinatorics — Catalan via C(2n,n)/(n+1)
// problem: demo — nth Catalan number C(n) = C(2n,n)/(n+1)
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Catalan Numbers
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/combinatorics/catalan-numbers.html

#include <bits/stdc++.h>
using namespace std;

// C(2n,n) via the exact product prod_{i=1..n} (n+i)/i, then divide by (n+1)
class Solution {
public:
    long long solve(int n) {
        long long c = 1;
        for (int i = 1; i <= n; i++) c = c * (n + i) / i;
        return c / (n + 1);
    }
};

int main() {
    // input: n   (0 <= n <= 35 so that C(n) fits in 64 bits)
    int n;
    if (!(cin >> n)) return 0;
    Solution sol;
    cout << sol.solve(n) << "\n";
    return 0;
}
