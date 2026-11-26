// binary_search_lower_bound_stl: std::lower_bound usage
// topic: easy/binary-search — C++ STL (lower bound)
// problem: LeetCode 35. Search Insert Position
// links:   https://leetcode.com/problems/search-insert-position/
//          https://leetcode.cn/problems/search-insert-position/
// reference:
//   Author(s): cppreference contributors
//   Date: 2026-11-26 (accessed)
//   Title: std::lower_bound
//   Code version: online article
//   Type: article
//   URL: https://en.cppreference.com/w/cpp/algorithm/lower_bound.html

#include <bits/stdc++.h>
using namespace std;

// std::lower_bound returns an iterator to the first element >= x.
// Subtracting begin() gives the insertion index (search insert position).
class Solution {
public:
    int solve(vector<int>& nums, int target) {
        return (int)(lower_bound(nums.begin(), nums.end(), target) - nums.begin());
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
