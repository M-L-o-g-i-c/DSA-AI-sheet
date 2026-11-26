// number_theory_sieve: Sieve of Eratosthenes
// topic: unhinged/number-theory — Sieve of Eratosthenes
// problem: LeetCode 204. Count Primes
// links:
//   https://leetcode.com/problems/count-primes/
//   https://leetcode.cn/problems/count-primes/
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Sieve of Eratosthenes
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

#include <bits/stdc++.h>
using namespace std;

// For each prime i, cross out its multiples from i*i onward (smaller
// multiples already have a smaller prime factor). What remains is prime.
class Solution {
public:
    int solve(int n) {
        if (n < 3) return 0;
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        for (int i = 2; (long long)i * i < n; i++) {
            if (!prime[i]) continue;
            for (int j = i * i; j < n; j += i) prime[j] = false;
        }
        return (int)count(prime.begin(), prime.end(), true);
    }
};

int main() {
    // input: n — output: number of primes strictly less than n
    int n;
    if (!(cin >> n)) return 0;
    Solution sol;
    cout << sol.solve(n) << "\n";
    return 0;
}
