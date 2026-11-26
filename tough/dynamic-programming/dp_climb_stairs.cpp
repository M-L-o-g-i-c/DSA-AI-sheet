// dp_climb_stairs: count ways to reach step n (1 or 2 steps at a time)
// topic: tough/dynamic-programming — linear DP (fibonacci recurrence)
// problem: LeetCode 70. Climbing Stairs
// links:
//   https://leetcode.com/problems/climbing-stairs/
//   https://leetcode.cn/problems/climbing-stairs/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Climbing Stairs
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/climbing-stairs/solution/

#include <bits/stdc++.h>
using namespace std;

// Ways to step i come from step i-1 (one big step) and i-2 (two small steps).
class Solution {
public:
    int solve(int n) {
        if (n <= 2) return n;
        int prev2 = 1, prev1 = 2;
        for (int i = 3; i <= n; i++) {
            int cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};

int main() {
    // input: n
    int n;
    if (!(cin >> n)) return 0;
    Solution sol;
    cout << sol.solve(n) << "\n";
    return 0;
}
