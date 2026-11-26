// binary_search_array: classic binary search on a sorted array
// topic: easy/binary-search — binary search array
// problem: LeetCode 704. Binary Search
// links:   https://leetcode.com/problems/binary-search/
//          https://leetcode.cn/problems/binary-search/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 704. Binary Search - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/binary-search/solution/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int target) {
        int lo = 0, hi = (int)nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};

int main() {
    // input: n target \n nums[0] ... nums[n-1]   (nums sorted ascending)
    int n, target;
    if (!(cin >> n >> target)) return 0;
    vector<int> nums(n);
    for (auto& v : nums) cin >> v;
    Solution sol;
    cout << sol.solve(nums, target) << "\n";
    return 0;
}
