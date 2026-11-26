// dp_basic: fibonacci by memoization vs tabulation
// topic: tough/dynamic-programming — memoization vs tabulation
// problem: demo — fibonacci(n) computed top-down and bottom-up
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

// Two directions of the same DP:
//   memoization = top-down, recurse and cache results
//   tabulation  = bottom-up, fill an array from base cases
class Solution {
public:
    // tabulation: dp[i] = dp[i-1] + dp[i-2], built forward
    long long solve(int n) {
        if (n <= 1) return n;
        vector<long long> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }

    // memoization: recurse on smaller n, cache each first computation
    long long solveMemo(int n) {
        vector<long long> memo(n + 1, -1);
        function<long long(int)> fib = [&](int k) -> long long {
            if (k <= 1) return k;
            if (memo[k] != -1) return memo[k];
            return memo[k] = fib(k - 1) + fib(k - 2);
        };
        return fib(n);
    }
};

int main() {
    // input: n   (n <= 90 so long long holds fib(n))
    int n;
    if (!(cin >> n)) return 0;
    Solution sol;
    cout << "memo: " << sol.solveMemo(n) << "\n";
    cout << "tab:  " << sol.solve(n) << "\n";
    return 0;
}
