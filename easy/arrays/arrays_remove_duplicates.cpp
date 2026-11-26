// arrays_remove_duplicates: remove duplicates in place from a sorted array
// topic: easy/arrays — two pointers (remove duplicates)
// problem: LeetCode 26. Remove Duplicates from Sorted Array
// links:   https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//          https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 26. Remove Duplicates from Sorted Array - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/remove-duplicates-from-sorted-array/solution/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // w is the write position: keep the first run of each value.
    int solve(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;
        int w = 1;
        for (int r = 1; r < n; r++) {
            if (nums[r] != nums[w - 1]) {
                nums[w] = nums[r];
                w++;
            }
        }
        return w;
    }
};

int main() {
    // input: n \n nums[0] ... nums[n-1]   (sorted ascending)
    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (auto& v : nums) cin >> v;
    Solution sol;
    int k = sol.solve(nums);
    // output: k \n then the first k values kept
    cout << k << "\n";
    for (int i = 0; i < k; i++) {
        if (i) cout << " ";
        cout << nums[i];
    }
    cout << "\n";
    return 0;
}
