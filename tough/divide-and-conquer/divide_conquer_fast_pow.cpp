// divide_conquer_fast_pow: x^n by squaring the half power (binary exponentiation)
// topic: tough/divide-and-conquer — fast power (binary exponentiation)
// problem: LeetCode 50. Pow(x, n)
// links:
//   https://leetcode.com/problems/powx-n/
//   https://leetcode.cn/problems/powx-n/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Pow(x, n)
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/powx-n/solution/

#include <bits/stdc++.h>
using namespace std;

// x^n = (x^(n/2))^2, times one extra x when n is odd. Negative n means 1/x^|n|.
class Solution {
public:
    double solve(double x, int n) {
        long long exp = n;   // widen first: n may be INT_MIN
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }
        function<double(long long)> fpow = [&](long long m) -> double {
            if (m == 0) return 1.0;
            double half = fpow(m / 2);
            return (m % 2 == 0) ? half * half : half * half * x;
        };
        return fpow(exp);
    }
};

int main() {
    // input: x n
    double x;
    int n;
    if (!(cin >> x >> n)) return 0;
    Solution sol;
    cout << sol.solve(x, n) << "\n";
    return 0;
}
