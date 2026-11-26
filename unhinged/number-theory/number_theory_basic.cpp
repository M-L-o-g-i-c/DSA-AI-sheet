// number_theory_basic: Euclidean gcd and lcm of two integers
// topic: unhinged/number-theory — how it works (gcd / lcm)
// problem: demo — gcd(a, b) and lcm(a, b)
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Euclidean algorithm for computing the greatest common divisor
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/algebra/euclid-algorithm.html

#include <bits/stdc++.h>
using namespace std;

// Euclid: gcd(a, b) = gcd(b, a mod b) until b = 0. lcm = a / gcd * b keeps
// the intermediate product small.
class Solution {
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

public:
    // returns {gcd(a, b), lcm(a, b)}
    pair<long long, long long> solve(long long a, long long b) {
        long long g = gcd(a, b);
        return {g, a / g * b};
    }
};

int main() {
    // input: a b (non-negative, not both zero) — output: "gcd lcm"
    long long a, b;
    if (!(cin >> a >> b)) return 0;
    Solution sol;
    auto [g, l] = sol.solve(a, b);
    cout << g << " " << l << "\n";
    return 0;
}
