// arrays_rotate: rotate the array to the right by k steps
// topic: easy/arrays — reverse-based rotation
// problem: LeetCode 189. Rotate Array
// links:   https://leetcode.com/problems/rotate-array/
//          https://leetcode.cn/problems/rotate-array/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 189. Rotate Array - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/rotate-array/solution/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // rotate by reversal: reverse all, then reverse each half.
    void solve(vector<int>& nums, int k) {
        int n = (int)nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    // input: n k \n nums[0] ... nums[n-1]   (n >= 1, k >= 0)
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> nums(n);
    for (auto& v : nums) cin >> v;
    Solution sol;
    sol.solve(nums, k);
    // output: rotated nums[0] ... nums[n-1]
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << nums[i];
    }
    cout << "\n";
    return 0;
}
