// two_pointers_remove_element: LeetCode 27 — in-place compaction with slow/fast pointers
// topic: easy/two-pointers — remove element
// problem: LeetCode 27. Remove Element
// links:
//   https://leetcode.com/problems/remove-element/
//   https://leetcode.cn/problems/remove-element/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 27. Remove Element - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/remove-element/solution/

#include <bits/stdc++.h>
using namespace std;

// Slow writes kept values, fast scans; order of kept elements does not matter.
class Solution {
public:
    int solve(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < (int)nums.size(); i++)
            if (nums[i] != val) nums[k++] = nums[i];
        return k;
    }
};

int main() {
    // input: n val \n a[0] ... a[n-1]
    // output: the new length, then the kept elements at the front of a
    int n, val;
    if (!(cin >> n >> val)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    int k = sol.solve(a, val);
    cout << k << "\n";
    for (int i = 0; i < k; i++) cout << a[i] << (i + 1 < k ? " " : "\n");
    return 0;
}
