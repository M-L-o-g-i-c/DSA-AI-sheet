// backtracking_permutations: build permutations one position at a time
// topic: tough/backtracking — permutation generation
// problem: LeetCode 46. Permutations
// links:
//   https://leetcode.com/problems/permutations/
//   https://leetcode.cn/problems/permutations/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Permutations
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/permutations/solution/

#include <bits/stdc++.h>
using namespace std;

// used[] tracks which elements are already placed in cur.
class Solution {
public:
    vector<vector<int>> solve(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        function<void()> dfs = [&]() {
            if ((int)cur.size() == (int)nums.size()) {
                res.push_back(cur);
                return;
            }
            for (int i = 0; i < (int)nums.size(); i++) {
                if (used[i]) continue;
                used[i] = true;           // choose
                cur.push_back(nums[i]);
                dfs();                    // explore
                cur.pop_back();           // unchoose
                used[i] = false;
            }
        };
        dfs();
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
    for (const auto& perm : res) {
        for (size_t i = 0; i < perm.size(); i++) {
            if (i) cout << " ";
            cout << perm[i];
        }
        cout << "\n";
    }
    return 0;
}
