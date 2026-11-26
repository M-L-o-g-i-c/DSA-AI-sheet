// bit_subsets_mask: enumerate all subsets with bitmask loops
// topic: medium/bit-manipulation — bitmask subset enumeration
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

// Bit i of mask decides whether nums[i] is in the subset; masks 0..2^n-1 cover all.
class Solution {
public:
    vector<vector<int>> solve(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> ans;
        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> cur;
            for (int i = 0; i < n; ++i)
                if (mask & (1 << i)) cur.push_back(nums[i]);
            ans.push_back(cur);
        }
        return ans;
    }
};

int main() {
    // input: n \n a[0] ... a[n-1]
    // output: one subset per line as "k v1 ... vk"
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    for (auto& s : sol.solve(a)) {
        cout << s.size();
        for (int v : s) cout << " " << v;
        cout << "\n";
    }
    return 0;
}
