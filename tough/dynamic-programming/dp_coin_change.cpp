// dp_coin_change: fewest coins summing to amount (unbounded knapsack)
// topic: tough/dynamic-programming — unbounded knapsack (min count)
// problem: LeetCode 322. Coin Change
// links:
//   https://leetcode.com/problems/coin-change/
//   https://leetcode.cn/problems/coin-change/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Coin Change
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/coin-change/solution/

#include <bits/stdc++.h>
using namespace std;

// dp[j] = fewest coins making amount j; coins are reusable (unbounded).
class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        const int INF = amount + 1;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for (int j = 1; j <= amount; j++) {
            for (int c : coins) {
                if (c <= j) dp[j] = min(dp[j], dp[j - c] + 1);
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }
};

int main() {
    // input: n amount \n coins[0] ... coins[n-1]
    int n, amount;
    if (!(cin >> n >> amount)) return 0;
    vector<int> coins(n);
    for (auto& v : coins) cin >> v;
    Solution sol;
    cout << sol.solve(coins, amount) << "\n";
    return 0;
}
