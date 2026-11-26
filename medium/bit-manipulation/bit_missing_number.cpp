// bit_missing_number: find the missing number in 0..n using XOR
// topic: medium/bit-manipulation — XOR of index and value
// problem: LeetCode 268. Missing Number
// links:
//   https://leetcode.com/problems/missing-number/
//   https://leetcode.cn/problems/missing-number/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Missing Number
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/missing-number/solution/

#include <bits/stdc++.h>
using namespace std;

// XOR every index 0..n with every value; pairs cancel, missing number stays.
class Solution {
public:
    int solve(vector<int>& nums) {
        int x = (int)nums.size();
        for (int i = 0; i < (int)nums.size(); ++i) x ^= i ^ nums[i];
        return x;
    }
};

int main() {
    // input: n \n a[0] ... a[n-1]   (n distinct values from 0..n, one missing)
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    cout << sol.solve(a) << "\n";
    return 0;
}
