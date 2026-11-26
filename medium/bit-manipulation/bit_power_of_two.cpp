// bit_power_of_two: check n is a power of two via n & (n - 1)
// topic: medium/bit-manipulation — single-bit check (n & (n-1))
// problem: LeetCode 231. Power of Two
// links:
//   https://leetcode.com/problems/power-of-two/
//   https://leetcode.cn/problems/power-of-two/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Power of Two
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/power-of-two/solution/

#include <bits/stdc++.h>
using namespace std;

// A power of two has exactly one bit set; n & (n - 1) clears the lowest set bit.
class Solution {
public:
    bool solve(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main() {
    // input: n
    int n;
    if (!(cin >> n)) return 0;
    Solution sol;
    cout << boolalpha << sol.solve(n) << "\n";
    return 0;
}
