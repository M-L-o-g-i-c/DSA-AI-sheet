// bit_single_number: find the element that appears once using XOR
// topic: medium/bit-manipulation — XOR cancellation
// problem: LeetCode 136. Single Number
// links:
//   https://leetcode.com/problems/single-number/
//   https://leetcode.cn/problems/single-number/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Single Number
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/single-number/solution/

#include <bits/stdc++.h>
using namespace std;

// Every pair x ^ x cancels to 0, so the XOR of everything is the single element.
class Solution {
public:
    int solve(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};

int main() {
    // input: n \n a[0] ... a[n-1]   (every value appears twice except one)
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    cout << sol.solve(a) << "\n";
    return 0;
}
