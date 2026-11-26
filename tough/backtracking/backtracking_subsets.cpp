// backtracking_subsets: generate all subsets via choose/explore/unchoose
// topic: tough/backtracking — subset generation
// problem: LeetCode 78. Subsets
// links:
//   https://leetcode.com/problems/subsets/
//   https://leetcode.cn/problems/subsets/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Subsets
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/subsets/solution/

#include <bits/stdc++.h>
using namespace std;

// At each step either skip nums[i] or include it; cur holds the subset in progress.
class Solution {
public:
    vector<vector<int>> solve(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int)> dfs = [&](int start) {
            res.push_back(cur);
            for (int i = start; i < (int)nums.size(); i++) {
                cur.push_back(nums[i]);   // choose
                dfs(i + 1);               // explore
                cur.pop_back();           // unchoose
            }
        };
        dfs(0);
        return res;
    }
};

int main() {
    // input: n \n nums[0] ... nums[n-1]
    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (auto& v : nums) cin >> v;
    Solution sol;
    vector<vector<int>> res = sol.solve(nums);
    for (const auto& subset : res) {
        for (size_t i = 0; i < subset.size(); i++) {
            if (i) cout << " ";
            cout << subset[i];
        }
        cout << "\n";
    }
    return 0;
}
