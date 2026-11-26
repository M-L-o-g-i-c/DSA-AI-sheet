// two_pointers_three_sum: LeetCode 15 — sort, fix one index, two-sum the rest
// topic: easy/two-pointers — 3sum
// problem: LeetCode 15. 3Sum
// links:
//   https://leetcode.com/problems/3sum/
//   https://leetcode.cn/problems/3sum/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 15. 3Sum - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/3sum/solution/

#include <bits/stdc++.h>
using namespace std;

// Sort first; for each fixed i run two-sum II on the tail, skipping duplicates.
class Solution {
public:
    vector<vector<int>> solve(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicate i
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum == 0) {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    lo++;
                    hi--;
                    while (lo < hi && nums[lo] == nums[lo - 1]) lo++;
                    while (lo < hi && nums[hi] == nums[hi + 1]) hi--;
                } else if (sum < 0) {
                    lo++;
                } else {
                    hi--;
                }
            }
        }
        return res;
    }
};

int main() {
    // input: n \n a[0] ... a[n-1]
    // output: one triplet per line, sorted (nothing if none)
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    for (const vector<int>& t : sol.solve(a))
        cout << t[0] << " " << t[1] << " " << t[2] << "\n";
    return 0;
}
