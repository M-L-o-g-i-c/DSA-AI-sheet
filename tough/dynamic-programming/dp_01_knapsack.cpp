// dp_01_knapsack: max value within capacity, each item used at most once
// topic: tough/dynamic-programming — 0/1 knapsack
// problem: demo — weights/values/capacity -> max value
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Knapsack Problem
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/dynamic_programming/knapsack.html

#include <bits/stdc++.h>
using namespace std;

// dp[j] = max value using capacity j; iterate j downwards so each item is
// used at most once (its old dp[j - w] cannot see the current item).
class Solution {
public:
    int solve(const vector<int>& weights, const vector<int>& values, int capacity) {
        vector<int> dp(capacity + 1, 0);
        for (size_t i = 0; i < weights.size(); i++) {
            int w = weights[i], v = values[i];
            for (int j = capacity; j >= w; j--) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
        return dp[capacity];
    }
};

int main() {
    // input: n W \n w[0] ... w[n-1] \n v[0] ... v[n-1]
    int n, W;
    if (!(cin >> n >> W)) return 0;
    vector<int> w(n), v(n);
    for (auto& x : w) cin >> x;
    for (auto& x : v) cin >> x;
    Solution sol;
    cout << sol.solve(w, v, W) << "\n";
    return 0;
}
