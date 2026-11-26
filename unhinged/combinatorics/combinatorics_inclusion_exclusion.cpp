// combinatorics_inclusion_exclusion: inclusion-exclusion over divisibility
// topic: unhinged/combinatorics — inclusion-exclusion (divisible by any prime)
// problem: demo — count numbers in [1, x] divisible by any of the given primes
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: The Inclusion-Exclusion Principle
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/combinatorics/inclusion-exclusion.html

#include <bits/stdc++.h>
using namespace std;

// count in [1,x] divisible by >=1 prime: add odd subsets, subtract even ones
class Solution {
public:
    long long solve(long long x, const vector<int>& p) {
        int m = (int)p.size();
        long long ans = 0;
        for (int mask = 1; mask < (1 << m); mask++) {
            long long prod = 1;
            bool over = false;
            for (int i = 0; i < m; i++) {
                if ((mask >> i) & 1) {
                    // stop early: if prod * p[i] > x the contribution is 0
                    if (prod > x / p[i]) { over = true; break; }
                    prod *= p[i];
                }
            }
            if (over) continue;
            long long cnt = x / prod;
            if (__builtin_popcount(mask) & 1) ans += cnt;
            else ans -= cnt;
        }
        return ans;
    }
};

int main() {
    // input: x m \n p[0] ... p[m-1]   (p[i] distinct primes, m <= 20)
    long long x;
    int m;
    if (!(cin >> x >> m)) return 0;
    vector<int> p(m);
    for (auto& v : p) cin >> v;
    Solution sol;
    cout << sol.solve(x, p) << "\n";
    return 0;
}
